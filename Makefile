# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/20 04:09:06 by jbyttner          #+#    #+#              #
#    Updated: 2015/09/20 13:03:18 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=eval_expr
CC=gcc
CFLAGS=-Wall -Wextra -Werror
SRC=eval_expr.c ft_atoi.c ft_double_list.c ft_putstr.c ft_strutil.c \
	main.c operator_util.c operators.c shunting_yard.c
OBJ=$(SRC:.c=.o)

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
