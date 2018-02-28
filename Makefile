# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/19 13:22:14 by ikozlov           #+#    #+#              #
#    Updated: 2018/02/27 22:52:33 by ikozlov          ###   ########.fr        #
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
	# echo $(SRC)
	# echo $(OBJ)
	gcc $(CFLAGS) $(DEBUG) -I $(LIBFT_DIR)includes/ -c $^

$(NAME): $(OBJ)
	gcc $(DEBUG) $(OBJ) -L $(LIBFT_DIR) -l $(LIBFT) -o $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re