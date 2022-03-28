##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-quentin.pages
## File description:
## Makefile
##

NAME = arcade_sfml.so

SRC = SfmlLib.cpp		\

OBJ = $(SRC:.cpp=.o)

FLAGLIB = -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)
	mv $(NAME) ../../lib/

$(NAME): $(OBJ)
	g++ -shared -fPIC $(SRC) -o $(NAME) $(FLAGLIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../lib/$(NAME)

re: fclean all