/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** libfoo
*/

#ifndef LIBFOO_HPP_
#define LIBFOO_HPP_
#include <iostream>
#include "../IDisplayModule.hpp"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

class SdlLib : public IDisplayModule
{
    public:
        SdlLib();
        ~SdlLib() = default;
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
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Surface *_surface;
        SDL_Texture *_texture;
        TTF_Font *_font;
        std::string _name;
};

#endif /* !LIBFOO_HPP_ */