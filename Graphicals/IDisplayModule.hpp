/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_HPP_
#define IDISPLAYMODULE_HPP_
#include <iostream>
#include <memory>
#include "unistd.h"
#include "../Core/Input.hpp"

class IDisplayModule {
    public :
        virtual ~IDisplayModule() = default ;
        virtual const std::string &getName() const = 0;
        virtual void createWindow() = 0;
        virtual Arcade::Input getInput() = 0;
        virtual void drawInterface() = 0;
        virtual void destroyWindow() = 0;
        virtual void setText(const std::string &string, const int &x, const int &y) = 0;
        virtual void display() = 0;
        virtual void drawScreen(const std::string &screen) = 0;
        virtual void drawPixel(const Arcade::Pixel &pixel) = 0;
};

#endif /* !IDISPLAYMODULE_HPP_ */
