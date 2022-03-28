/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** main
*/

#include <iostream>
#include "Charge.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "./[EXECUTABLE] ./lib/[LIB.SO]" << std::endl;
        return (EXIT_FAILURE);
    }
    std::string libname(argv[1]);
    auto charge = std::make_unique<Charge>(libname);
    charge->start();

    return (EXIT_SUCCESS);
}