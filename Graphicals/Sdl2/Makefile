##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-quentin.pages
## File description:
## Makefile
##

NAME = arcade_sdl2.so

SRC = SdlLib.cpp		\

OBJ = $(SRC:.cpp=.o)

FLAGLIB = -lSDL2 -lSDL2_ttf -lSDL2_image

all: $(NAME)
	mv $(NAME) ../../lib/

$(NAME): $(OBJ)
	g++ -fPIC -shared $(SRC) -o $(NAME) $(FLAGLIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../lib/$(NAME)

re: fclean all