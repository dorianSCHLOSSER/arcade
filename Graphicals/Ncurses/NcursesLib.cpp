/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** NcursesLib
*/

#include "NcursesLib.hpp"

extern "C" {
    IDisplayModule *entryPoint()
    {
        return (new NcursesLib());
    }
}

NcursesLib::NcursesLib() : _name("NcursesLib") {}


const std::string &NcursesLib::getName() const
{
    return (_name);
}

void NcursesLib::createWindow()
{
    initscr();
    start_color();
    noecho();
    curs_set(0);
    getmaxyx(stdscr, max_y, max_x);
    _window = subwin(stdscr, max_y, max_x, 0, 0);
    keypad(_window, TRUE);
}

Arcade::Input NcursesLib::getInput()
{
    auto input = wgetch(_window);
    wtimeout(_window, 50);
    switch (input) {
        case KEY_UP :
            return (Arcade::Input::UP);
        case KEY_DOWN :
            return (Arcade::Input::DOWN);
        case KEY_RIGHT :
            return (Arcade::Input::RIGHT);
        case KEY_LEFT :
            return (Arcade::Input::LEFT);
        case KEY_F(2) :
            return (Arcade::Input::F2);
        case KEY_F(3) :
            return (Arcade::Input::F3);
        case KEY_F(4) :
            return (Arcade::Input::F4);
        case KEY_BACKSPACE :
            return (Arcade::Input::BACKSPACE);
        case 'a' :
            return (Arcade::Input::A_KEY);
        case 'b' :
            return (Arcade::Input::B_KEY);
        case 'c' :
            return (Arcade::Input::C_KEY);
        case 'd' :
            return (Arcade::Input::D_KEY);
        case 'e' :
            return (Arcade::Input::E_KEY);
        case 'f' :
            return (Arcade::Input::F_KEY);
        case 'g' :
            return (Arcade::Input::G_KEY);
        case 'h' :
            return (Arcade::Input::H_KEY);
        case 'i' :
            return (Arcade::Input::I_KEY);
        case 'j' :
            return (Arcade::Input::J_KEY);
        case 'k' :
            return (Arcade::Input::K_KEY);
        case 'l' :
            return (Arcade::Input::L_KEY);
        case 'm' :
            return (Arcade::Input::M_KEY);
        case 'n' :
            return (Arcade::Input::N_KEY);
        case 'o' :
            return (Arcade::Input::O_KEY);
        case 'p' :
            return (Arcade::Input::P_KEY);
        case 'q' :
            return (Arcade::Input::Q_KEY);
        case 'r' :
            return (Arcade::Input::R_KEY);
        case 's' :
            return (Arcade::Input::S_KEY);
        case 't' :
            return (Arcade::Input::T_KEY);
        case 'u' :
            return (Arcade::Input::U_KEY);
        case 'v' :
            return (Arcade::Input::V_KEY);
        case 'w' :
            return (Arcade::Input::W_KEY);
        case 'x' :
            return (Arcade::Input::X_KEY);
        case 'y' :
            return (Arcade::Input::Y_KEY);
        case 'z' :
            return (Arcade::Input::Z_KEY);
        case 10 :
            return (Arcade::Input::ENTER);
        case 27 :
            return (Arcade::Input::ESCAPE);
        default :
            return (Arcade::Input::NO_INPUT);
    }
    return (Arcade::Input::NO_INPUT);
}

void NcursesLib::drawInterface()
{
    werase(_window);
    wrefresh(_window);
    setText("Arcade : Ncurses Graphics", 800, 150);
}

void NcursesLib::destroyWindow()
{
    werase(_window);
    endwin();
}

void NcursesLib::setText(const std::string &string, const int &x, const int &y)
{
    auto indX = ((x * 100) / 1920);
    indX = ((indX * max_x) / 100);
    auto indY = ((y * 100) / 1080);
    indY = ((indY * max_y) / 100);

    mvwprintw(_window, indY, indX, "                                   ");
    wattron(_window, A_BOLD);
    mvwprintw(_window, indY, indX, string.c_str());
    wattroff(_window, A_BOLD);
}

void NcursesLib::display()
{
    wrefresh(_window);
}

void NcursesLib::drawScreen(const std::string &screen)
{
    werase(_window);
    wrefresh(_window);
}

void NcursesLib::drawPixel(const Arcade::Pixel &pixel)
{ 
    auto x = 70 + (pixel.x);
    auto y = 2 + (pixel.y);
    wattron(_window, A_BOLD);
    mvwprintw(_window, y, x, pixel.ncursesGame.c_str());
    wattroff(_window, A_BOLD);
}