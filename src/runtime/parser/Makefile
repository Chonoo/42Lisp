# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2015/09/21 17:58:01 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=runtimeparser.a
SRC=shunting_yard.c	stringparser.c
ROOTDIR=../../../
LIBDIR=$(ROOTDIR)lib/
BINDIR=$(ROOTDIR)bin/
INCDIR=$(ROOTDIR)include/
BUILDDIR=$(ROOTDIR)build/
DIR=src/runtime/parser/

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -O3 -c
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I$(INCDIR) $(SRC)
	$(AR) $(ARFLAGS) $(LIBDIR)$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

r: fclean all
