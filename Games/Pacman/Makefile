##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-quentin.pages
## File description:
## Makefile
##

NAME = arcade_pacman.so

SRC = Pacman.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)
	mv $(NAME) ../../lib/

$(NAME): $(OBJ)
	g++ -fPIC -shared $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../lib/$(NAME)

re: fclean all