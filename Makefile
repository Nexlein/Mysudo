##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=	$(shell find -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sudo

CFLAGS	=	-W -Wall -Wextra -g3 -lcrypt

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

perm:
	sudo chown root:root my_sudo
	sudo chmod u+s,g+s my_sudo

fclean:	clean
	rm -f $(NAME)

re: fclean all
