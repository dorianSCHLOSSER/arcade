/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** NcursesLib
*/

#ifndef LIBBAR_HPP_
#define LIBBAR_HPP_
#include <iostream>
#include "../IDisplayModule.hpp"
#include "ncurses.h"

class NcursesLib : public IDisplayModule
{
    public:
        NcursesLib();
        ~NcursesLib() = default;
        const std::string &getName() const;
        void createWindow();
        Arcade::Input getInput();
        void drawInterface();
        void destroyWindow();
        void setText(const std::string &string, const int &x, const int &y);
        void display();
        void drawScreen(const std::string &screen);
        void drawPixel(const Arcade::Pixel &pixel);
    protected:
    private:
        WINDOW *_window;
        std::string _name;
        int max_x;
        int max_y;
};

#endif /* !LIBBAR_HPP_ */
