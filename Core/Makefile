##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-quentin.pages
## File description:
## Makefile
##

NAME = arcade

SRC = 	Charge.cpp			\
		main.cpp			\
		Core.cpp

all: $(NAME)
	mv $(NAME) ../

OBJ	=	$(SRC:.cpp=.o)

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME) -ldl

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all