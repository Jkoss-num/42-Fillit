# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/21 21:35:29 by otiffiny          #+#    #+#              #
#    Updated: 2019/12/24 20:56:13 by otiffiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBFT = -L libft/ -lft
SRC = backtr.c collision.c create_square.c fillit.c list.c move_coord.c size.c type.c valid.c
OBJ = backtr.o collision.o create_square.o fillit.o list.o move_coord.o size.o type.o valid.o

all: $(NAME)

$(NAME): $(OBJ) fillit.h
	make -C libft
	@gcc -Wall -Wextra -Werror $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(SRC)
	@gcc -Wall -Wextra -Werror -c $(SRC) -I libft/includes

clean:
	@/bin/rm -f $(OBJ)
	make clean -C libft

fclean: clean
	@/bin/rm -f $(NAME)
	make fclean -C libft

re: fclean all