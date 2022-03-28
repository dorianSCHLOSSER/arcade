/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Charge
*/

#include "Charge.hpp"

Charge::Charge(const std::string &selected)
        : _selected(selected)
{
    if (_selected != "./lib/arcade_ncurses.so" &&
        _selected != "./lib/arcade_sfml.so" &&
        _selected != "./lib/arcade_sdl2.so") {
            std::cerr <<  "ERROR LIB: " << selected << std::endl;
            exit(84);
        }
    _libraries.push_back(std::make_shared<DLLoader<IDisplayModule>>("./lib/arcade_ncurses.so"));
    _libraries.push_back(std::make_shared<DLLoader<IDisplayModule>>("./lib/arcade_sfml.so"));
    _libraries.push_back(std::make_shared<DLLoader<IDisplayModule>>("./lib/arcade_sdl2.so"));
    _games.push_back(std::make_shared<DLLoader<IGames>>("./lib/arcade_nibbler.so"));
    _games.push_back(std::make_shared<DLLoader<IGames>>("./lib/arcade_pacman.so"));
    if (_selected == "./lib/arcade_ncurses.so") _libInd = 0;
    else if (_selected == "./lib/arcade_sfml.so") _libInd = 1;
    else if (_selected == "./lib/arcade_sdl2.so") _libInd = 2;
    else exit(84);
    _core = std::make_unique<Core>(_libraries, _games, _libInd);
}

void Charge::start()
{
    _core->loop();
}