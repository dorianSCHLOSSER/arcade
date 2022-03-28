##
## EPITECH PROJECT, 2021
## B-OOP-400-STG-4-1-arcade-quentin.pages
## File description:
## Makefile
##

all:
	make -C ./Graphicals/
	make -C ./Games/
	make -C ./Core/

graphicals:
	make -C ./Graphicals/

core:
	make -C ./Core/

games:
	make -C ./Games/

clean:
	make clean -C ./Graphicals/
	make clean -C ./Games/
	make clean -C ./Core/

fclean:
	make fclean -C./Graphicals/
	make fclean -C ./Games/
	make fclean -C ./Core/

re:
	make re -C ./Graphicals/
	make re -C ./Games/
	make re -C ./Core/