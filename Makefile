# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 20:18:54 by myli-pen          #+#    #+#              #
#    Updated: 2025/05/13 01:03:53 by myli-pen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = libftprintf.a
LIB = libft.a
TEST = main.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
DIR_INC = includes
DIR_SRC = src
DIR_LIB = libft
DIR_OBJ = obj

SRCS = $(addprefix $(DIR_SRC)/, ft_printf.c ft_printf_utils.c)
OBJS = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SRCS))

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(DIR_LIB)

$(DIR_OBJ):
	@mkdir $(DIR_OBJ)

$(NAME): $(LIB) $(DIR_OBJ) $(OBJS)
	@mv $(LIB) $(NAME)
	@ar -rcs $(NAME) $(OBJS)
	@echo "\033[1;33m [✔] $(NAME) created \033[0m"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(DIR_INC)
	@echo "\033[1;32m [+]\033[0m compiling $@"

clean:
	@rm -rf $(DIR_OBJ)
	@echo "\033[1;31m [-]\033[0m removed ft_printf .o files"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[1;31m [-]\033[0m removed $(NAME)"
	@make fclean -C $(DIR_LIB)

re: fclean all

test:
	@$(CC) -g $(CFLAGS) $(TEST) $(NAME) -I$(DIR_INC)
	@echo ""
	@valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes \
	--track-origins=yes ./a.out
	@rm -rf a.out

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re test
