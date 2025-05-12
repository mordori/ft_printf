# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/02 20:18:54 by myli-pen          #+#    #+#              #
#    Updated: 2025/05/12 15:24:20 by myli-pen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL = all
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory
DIR_INC = ./includes/
DIR_SRC = ./src/
DIR_LIB = ./libft/
LIB = libft.a
TEST = main.c

SRCS =	$(addprefix $(DIR_SRC), ft_printf.c ft_printf_utils.c)
OBJS = $(SRCS:.c=.o)

all: $(LIB) $(NAME)

$(LIB):
	@make -C $(DIR_LIB)

$(NAME): $(LIB) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\033[1;33m [✔] $(NAME) created \033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(DIR_INC)
	@echo "\033[1;32m [+]\033[0m compiling $@"

clean:
	@rm -rf $(OBJS)
	@echo "\033[1;31m [-]\033[0m removed ft_printf .o files"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf a.out
	@echo "\033[1;31m [-]\033[0m removed $(NAME)"
	@make fclean -C $(DIR_LIB)

re: fclean all

test: $(LIB) $(NAME)
	@$(CC) -g $(CFLAGS) $(TEST) $(NAME) $(LIB) -I$(DIR_INC)
	@echo ""
	@./a.out

.SECONDARY: $(OBJS)
.PHONY: all clean fclean re test
