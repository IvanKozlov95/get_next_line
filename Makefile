# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 13:22:14 by ikozlov           #+#    #+#              #
#    Updated: 2018/03/22 19:28:49 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

# directories
OBJ_DIR = obj/
LIBFT_DIR = libft/

# complier
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g

# src & obj files
SRC = get_next_line.c \
	main.c 
OBJ = $(SRC:%.c=%.o)

# libraries
LIBFT = ft

all:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) $(NAME)

$(OBJ): $(SRC)
	@gcc $(CFLAGS) $(DEBUG) -I $(LIBFT_DIR)includes/ -c $^

$(NAME): $(OBJ)
	@gcc $(DEBUG) $(OBJ) -L $(LIBFT_DIR) -l $(LIBFT) -o $(NAME)
	@echo "\`gnl\` [INFO] Complied"

clean:
	@/bin/rm -f $(OBJ)
	@echo "\`gnl\` [INFO] Object files removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\`gnl\` [INFO] Executable removed"

re: fclean all

.PHONY: all clean fclean re