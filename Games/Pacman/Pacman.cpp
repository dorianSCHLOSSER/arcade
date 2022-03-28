/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include <fstream>

extern "C" {
    IGames *entryPoint()
    {
        return (new Pacman());
    }
}

Pacman::Pacman() : _name("Pacman"), _left(Arcade::Input::LEFT),
_right(Arcade::Input::RIGHT), _up(Arcade::Input::UP), 
_down(Arcade::Input::DOWN), _currentInput(Arcade::Input::NO_INPUT),
_check(Arcade::Input::NO_INPUT), _restart(Arcade::Input::R_KEY)
{
    start();
}

const std::string &Pacman::getName() const
{
    return (_name);
}

std::string Pacman::getScreen()
{
    return ("Rscr/screenNibbler.png");
}

void Pacman::start()
{
    _currentInput = Arcade::Input::NO_INPUT;
    _ghosts.clear();
    _pacman.clear();
    _pixel.clear();
    _point.clear();
    _score = 0;
    std::ifstream map("Rscr/pacman.map");
    std::string line;
    for (int horizon = 0 ; horizon < 50 ; horizon++) {
        std::getline(map, line);
        for (int vertical = 0 ; vertical < 50 ; vertical++) {
            if (line[vertical] == '#')
                _pixel.push_back({horizon, vertical, "Rscr/wallPacman.png", "#"});
            else if (line[vertical] == '*')
                _point.push_back({horizon, vertical, "Rcsr/point.png", "œ"});
        }
    }
}

std::vector<std::vector<Arcade::Pixel>> Pacman::getAllPixel()
{
    std::vector<std::vector<Arcade::Pixel>> allPixel;
    allPixel.push_back(_pixel);
    return (allPixel);
}

void Pacman::getInput(const Arcade::Input &input)
{
    return;
}

void Pacman::move()
{
    return;
}

void Pacman::up()
{
    return;
}

void Pacman::down()
{
    return;
}

void Pacman::left()
{
    return;
}

void Pacman::right()
{
    return;
}

const int &Pacman::getScore() const
{
    return (_score);
}

void Pacman::point()
{
    return;
}