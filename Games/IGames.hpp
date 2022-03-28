/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** IGames
*/

#ifndef IGAMES_HPP_
#define IGAMES_HPP_
#include <iostream>
#include <vector>
#include "../Core/Input.hpp"

class IGames {
    public:
        virtual ~IGames() = default;
        virtual const std::string &getName() const = 0;
        virtual std::string getScreen() = 0;
        virtual void start() = 0;
        virtual std::vector<std::vector<Arcade::Pixel>> getAllPixel() = 0;
        virtual void getInput(const Arcade::Input &input) = 0;
        virtual void up() = 0;
        virtual void down() = 0;
        virtual void left() = 0;
        virtual void right() = 0;
        virtual void move() = 0;
        virtual const int &getScore() const = 0;
};

#endif /* !IGAMES_HPP_ */
