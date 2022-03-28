/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** SfmlLib
*/

#ifndef LIBGRA_HPP_
#define LIBGRA_HPP_
#include <iostream>
#include "../IDisplayModule.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class SfmlLib : public IDisplayModule
{
    public:
        SfmlLib();
        ~SfmlLib() = default;
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
        std::string _name;
        sf::RenderWindow _window;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Font _font;
};

#endif /* !LIBGRA_HPP_ */