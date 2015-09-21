# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 14:08:01 by jbyttner          #+#    #+#              #
#    Updated: 2015/09/21 17:10:30 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libolist.a
SRC=ft_o_list.c
ROOTDIR=../../../
LIBDIR=$(ROOTDIR)lib/
BINDIR=$(ROOTDIR)bin/
INCDIR=$(ROOTDIR)include/
OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -c

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
