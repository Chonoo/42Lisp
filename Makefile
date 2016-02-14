

SRC=*.c

all:
	gcc -g -I libft/includes -Wall -Wextra *.c -o 42lisp -L libft -lft

fclean:
	rm 42lisp
