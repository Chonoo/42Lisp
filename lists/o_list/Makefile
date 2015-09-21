# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 14:08:01 by jbyttner          #+#    #+#              #
#    Updated: 2015/09/21 16:21:50 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libolist.a
SRC=ft_o_list.c
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
