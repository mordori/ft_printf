# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 20:18:54 by myli-pen          #+#    #+#              #
#    Updated: 2025/06/29 09:05:46 by myli-pen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = libftprintf.a
LIB = libft.a
PROGRAM = program
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
DIR_LIB = libft
DIR_SRC = src
DIR_OBJ = obj
DIR_DEP = dep

SRCS = $(addprefix $(DIR_SRC)/, \
		ft_printf.c ft_printf_utils.c)
OBJS = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))
DEPS = $(patsubst $(DIR_SRC)/%.c, $(DIR_DEP)/%.d, $(SRCS))

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(DIR_LIB)
	@mkdir -p $(DIR_OBJ) $(DIR_DEP)

$(NAME): $(LIB) $(OBJS)
	@cp $(LIB) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@echo "\033[1;33m [✔] $(NAME) created \033[0m"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ \
	-MMD -MP -MF $(patsubst $(DIR_OBJ)/%.o, $(DIR_DEP)/%.d, $@)
	@echo "\033[1;32m [+]\033[0m compiling $@"

clean:
	@rm -rf $(DIR_OBJ) $(DIR_DEP)
	@echo "\033[1;31m [-]\033[0m removed ./obj/"
	@echo "\033[1;31m [-]\033[0m removed ./dep/"

fclean: clean
	@rm -rf $(PROGRAM)
	@rm -rf $(NAME)
	@echo "\033[1;31m [-]\033[0m removed $(PROGRAM)"
	@echo "\033[1;31m [-]\033[0m removed $(NAME)"
	@make fclean -C $(DIR_LIB)

re: fclean all

test: $(NAME)
	@$(CC) -g $(CFLAGS) -o $(PROGRAM) main.c $(NAME)
	@echo "\033[1;33m [✔] $(PROGRAM) created \033[0m\n"
	./$(PROGRAM)

.PHONY: all clean fclean re test
.SECONDARY: $(OBJS) $(DEPS)

-include $(DEPS)
