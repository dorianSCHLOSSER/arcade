/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Nibbler
*/

#include "Nibbler.hpp"
#include <fstream>

extern "C" {
    IGames *entryPoint()
    {
        return (new Nibbler());
    }
}

Nibbler::Nibbler() : _name("Nibbler"), _left(Arcade::Input::LEFT), 
_right(Arcade::Input::RIGHT), _up(Arcade::Input::UP), 
_down(Arcade::Input::DOWN), _currentInput(Arcade::Input::NO_INPUT),
_check(Arcade::Input::LEFT), _restart(Arcade::Input::R_KEY)
{
    start();
}

const std::string &Nibbler::getName() const
{
    return (_name);
}

std::string Nibbler::getScreen()
{
    return ("Rscr/screenNibbler.png");
}

void Nibbler::start()
{
    _currentInput = Arcade::Input::NO_INPUT;
    _check = Arcade::Input::LEFT;
    _apple.clear();
    _pixel.clear();
    _snake.clear();
    _score = 0;
    std::ifstream map("Rscr/nibbler.map");
    std::string line;
    for (int horizon = 0 ; horizon < 50 ; horizon++) {
        std::getline(map, line);
        for (int vertical = 0 ; vertical < 50 ; vertical++) {
            if (line[vertical] == '#')
                _pixel.push_back({horizon, vertical, "Rscr/wallNibbler.png", "#"});
            else if (line[vertical] == 'A')
                _apple.push_back({horizon, vertical, "Rscr/apple.png", "@"});
        }
    }
    _snake.push_back({20, 25, "Rscr/snake_left.png", "0"});
    _snake.push_back({21, 25, "Rscr/snake_body_horizontal.png", "O"});
    _snake.push_back({22, 25, "Rscr/snake_body_horizontal.png", "O"});
    _snake.push_back({23, 25, "Rscr/snake_body_horizontal.png", "O"});
    _snake.push_back({24, 25, "Rscr/snake_body_horizontal.png", "O"});
}

std::vector<std::vector<Arcade::Pixel>> Nibbler::getAllPixel()
{
    std::vector<std::vector<Arcade::Pixel>> allPixel;
    allPixel.push_back(_pixel);
    allPixel.push_back(_snake);
    allPixel.push_back(_apple);
    return (allPixel);
}

void Nibbler::getInput(const Arcade::Input &input)
{
    if (input == _up) _currentInput = input;
    if (input == _down) _currentInput = input;
    if (input == _left) _currentInput = input;
    if (input == _right) _currentInput = input;
    if (input == _restart) _currentInput = input;
}

void Nibbler::move()
{
    if (_currentInput == _up) {
        if (_check == _down) down();
        else up();
    }
    if (_currentInput == _down) {
        if (_check == _up) up();
        else down();
    }
    if (_currentInput == _left) {
        if (_check == _right) right();
        else left();
    }
    if (_currentInput == _right) {
        if (_check == _left) left();
        else right();
    }
    if (_currentInput == _restart) {
        start();
        return;
    }
}

void Nibbler::up()
{
    int i = 0;
    Arcade::Pixel snake = _snake[0];
    Arcade::Pixel S_snake = {-20, -20, "Rscr/snake_left.png", "0"};
    snake.screenGame = "Rscr/snake_up.png";
    for (auto &check : _pixel) {
        if (snake.x == check.x && snake.y - 1 == check.y) {
            start();
            return;
        }
    }
    for (auto &check : _snake) {
        if (i == 0) {
            i++;
            continue;
        }
        if (snake.x == check.x && snake.y - 1 == check.y) {
            start();
            return;
        }
        i++;
    }
    if (snake.x == _apple[0].x && snake.y - 1 == _apple[0].y) {
        _score += 10;
        _snake.push_back(S_snake);
        _snake.push_back(S_snake);
        apple();
    }
    snake.y -= 1;
    _snake.erase(_snake.end() + 1);
    _snake.insert(_snake.begin(), snake);
    _snake[1].screenGame = "Rscr/snake_body_vertical.png";
    _snake[1].ncursesGame = "O";
    _currentInput = _up;
    _check = _up;
}

void Nibbler::down()
{
    int i = 0;
    Arcade::Pixel snake = _snake[0];
    Arcade::Pixel S_snake = {-20, -20, "Rscr/snake_left.png", "0"};
    snake.screenGame = "Rscr/snake_down.png";
    for (auto &check : _pixel) {
        if (snake.x == check.x  && snake.y + 1 == check.y) {
            start();
            return;
        }
    }
    for (auto &check : _snake) {
        if (i == 0) {
            i++;
            continue;
        }
        if (snake.x == check.x && snake.y + 1 == check.y) {
            start();
            return;
        }
        i++;
    }
    if (snake.x == _apple[0].x && snake.y + 1 == _apple[0].y) {
        _score += 10;
        _snake.push_back(S_snake);
        _snake.push_back(S_snake);
        apple();
    }
    snake.y += 1;
    _snake.erase(_snake.end() + 1);
    _snake.insert(_snake.begin(), snake);
    _snake[1].screenGame = "Rscr/snake_body_vertical.png";
    _snake[1].ncursesGame = "O";
    _currentInput = _down;
    _check = _down;
}

void Nibbler::left()
{
    int i = 0;
    Arcade::Pixel snake = _snake[0];
    Arcade::Pixel S_snake = {-20, -20, "Rscr/snake_left.png", "0"};
    snake.screenGame = "Rscr/snake_left.png";
    for (auto &check : _pixel) {
        if (snake.x == check.x + 1 && snake.y == check.y) {
            start();
            return;
        }
    }
    for (auto &check : _snake) {
        if (i == 0) {
            i++;
            continue;
        }
        if (snake.x == check.x + 1 && snake.y == check.y) {
            start();
            return;
        }
        i++;
    }
    if (snake.x == _apple[0].x + 1 && snake.y == _apple[0].y) {
        _score += 10;
        _snake.push_back(S_snake);
        _snake.push_back(S_snake);
        apple();
    }
    snake.x -= 1;
    _snake.erase(_snake.end() + 1);
    _snake.insert(_snake.begin(), snake);
    _snake[1].screenGame = "Rscr/snake_body_horizontal.png";
    _snake[1].ncursesGame = "O";
    _currentInput = _left;
    _check = _left;
}

void Nibbler::right()
{
    int i = 0;
    Arcade::Pixel snake = _snake[0];
    Arcade::Pixel S_snake = {-20, -20, "Rscr/snake_left.png", "0"};
    snake.screenGame = "Rscr/snake_right.png";
    for (auto &check : _pixel) {
        if (snake.x == check.x - 1 && snake.y == check.y) {
            start();
            return;
        }
    }
    for (auto &check : _snake) {
        if (i == 0) {
            i++;
            continue;
        }
        if (snake.x == check.x - 1 && snake.y == check.y) {
            start();
            return;
        }
        i++;
    }
    if (snake.x == _apple[0].x - 1 && snake.y == _apple[0].y) {
        _score += 10;
        _snake.push_back(S_snake);
        _snake.push_back(S_snake);
        apple();
    }
    snake.x += 1;
    _snake.erase(_snake.end() + 1);
    _snake.insert(_snake.begin(), snake);
    _snake[1].screenGame = "Rscr/snake_body_horizontal.png";
    _snake[1].ncursesGame = "O";
    _currentInput = _right;
    _check = _right;
}

void Nibbler::apple()
{
    _apple.clear();
    auto x = rand()%45 + 5;
    auto y = rand()%45 + 5;
    bool check = false;
    _apple.push_back({x, y, "Rscr/apple.png", "@"});

    for (auto &map : _pixel) {
        if (x == map.x && y == map.y) check = true;
    }
    if (check == true) apple();
}

const int &Nibbler::getScore() const
{
    return (_score);
}