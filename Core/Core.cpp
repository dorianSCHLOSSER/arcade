/*
** EPITECH PROJECT, 2021
** Boostrap_Arcade
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(std::vector<std::shared_ptr<DLLoader<IDisplayModule>>> libraries,
    std::vector<std::shared_ptr<DLLoader<IGames>>> games,
    int libInd)
    : _libraries(std::move(libraries)), _libInd(libInd),
    _currentLib(_libraries[_libInd]),
    _games(std::move(games)), _gamesInd(0),
    _currentGames(_games[_gamesInd]),
    _quit(false), _menu(true), _name("Bot")
{
    _currentLib->getInstance()->createWindow();
}

void Core::directionLibrary(bool direction)
{
    if (direction == true) {
        if (_libInd > 0) {
            _libInd = _libInd - 1;
            _currentLib->getInstance()->destroyWindow();
            _currentLib = _libraries[_libInd];
            _currentLib->getInstance()->createWindow();
        }
        return;
    }
    else {
        if (_libInd < 2) {
            _libInd = _libInd + 1;
            _currentLib->getInstance()->destroyWindow();
            _currentLib = _libraries[_libInd];
            _currentLib->getInstance()->createWindow();
        }
        return;
    }
}

void Core::keyEvents(const Arcade::Input &input)
{
    switch (input) {
        case Arcade::Input::F2 :
            _quit = true;
            break;
        case Arcade::Input::ESCAPE :
            _menu = true;
            break;
        case Arcade::Input::F3 :
            directionLibrary(true);
            break;
        case Arcade::Input::F4 :
            directionLibrary(false);
            break;
        case Arcade::Input::ENTER :
            _menu = false;
            break;
        default :
            break;
    }
}

void Core::directionGame(bool direction)
{
    if (direction == true) {
        if (_gamesInd != 0)
        _gamesInd = _gamesInd - 1;
    }
    else {
        if (_gamesInd != 1)
            _gamesInd = _gamesInd + 1;
    }
    _currentGames = _games[_gamesInd];
}

void Core::Menu(Arcade::Input &input)
{
    switch (input) {
        case Arcade::Input::DOWN :
            directionGame(false);
            break;
        case Arcade::Input::UP :
            directionGame(true);
            break;
        case Arcade::Input::ENTER :
            _menu = false;
            break;
        default :
            break;
    }
    if (!_name.empty() && input == Arcade::Input::BACKSPACE)
        _name = _name.substr(0, _name.size() - 1);
    if (_name.size() < 20) {
        if (input >= Arcade::Input::A_KEY && input <= Arcade::Input::Z_KEY) {
            _name += static_cast<char>('A') + input;
        }
    }
    _currentLib->getInstance()->setText("NAME : " + _name, 100, 150);
    int index = 0;
    int space = 450;
    for (auto &i : _games) {
        if (index == _gamesInd)
            _currentLib->getInstance()->setText("[ " +  _currentGames->getInstance()->getName() + " ]", 1200, space);
        else
            _currentLib->getInstance()->setText("  " +  _games[index]->getInstance()->getName() + "  ", 1200, space);
        index += 1;
        space += 50;
    }
}

void Core::startGame(Arcade::Input &input)
{
    _currentLib->getInstance()->drawScreen(_currentGames->getInstance()->getScreen());
    _currentLib->getInstance()->setText("Score : " + std::to_string(_currentGames->getInstance()->getScore()), 140, 350);
    _currentGames->getInstance()->getInput(input);
    _currentGames->getInstance()->move();
    auto pixel = _currentGames->getInstance()->getAllPixel();
    drawAllGame(pixel);
}


void Core::printLibraries()
{
    _currentLib->getInstance()->setText("GRAPHICAL", 600, 300);
    int index = 0;
    int space = 450;
    for (auto &i : _libraries) {
        if (index == _libInd)
            _currentLib->getInstance()->setText("[ " +  _currentLib->getInstance()->getName() + " ]", 600, space);
        else
            _currentLib->getInstance()->setText(" " +  _libraries[index]->getInstance()->getName(), 600, space);
        index += 1;
        space += 50;
    }
    _currentLib->getInstance()->setText("NAME : " + _name, 100, 150);
    _currentLib->getInstance()->setText("Press Escape to open Menu.", 800, 650);
    _currentLib->getInstance()->setText("Press F2 to exit.", 800, 680);
    _currentLib->getInstance()->setText("Press F4 to change Library (up).", 800, 740);
    _currentLib->getInstance()->setText("Press F3 to change Library (down).", 800, 710);
    _currentLib->getInstance()->setText("Press R to restart game.", 800, 770);
    _currentLib->getInstance()->setText("Press UP or DOWN for change Game.", 800, 800);
    _currentLib->getInstance()->setText("Press Enter for start game !", 800, 830);
}

void Core::loop()
{
    while (!_quit) {
        auto input = _currentLib->getInstance()->getInput();
        keyEvents(input);
        _currentLib->getInstance()->drawInterface();
        printLibraries();
        if (_menu == true) Menu(input);
        else {
            startGame(input);
        }
        _currentLib->getInstance()->display();
    }
    _currentLib->getInstance()->destroyWindow();
}

void Core::drawAllGame(const std::vector<std::vector<Arcade::Pixel>> &all)
{
    for (const auto &mapY : all) {
        for (const auto &mapX : mapY) {
                _currentLib->getInstance()->drawPixel(mapX);
        }
    }
}