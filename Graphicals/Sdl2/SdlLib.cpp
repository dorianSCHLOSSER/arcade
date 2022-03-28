/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** SdlLib
*/

#include "SdlLib.hpp"

extern "C" {
    IDisplayModule *entryPoint()
    {
        return (new SdlLib());
    }
}

SdlLib::SdlLib() : _name("SdlLib") {}

const std::string &SdlLib::getName() const
{
    return (_name);
}

void SdlLib::createWindow()
{
    if (SDL_Init(SDL_INIT_VIDEO < 0)) {
        std::cerr << "ERROR initialization" << std::endl;
        exit(EXIT_FAILURE);
    }
    _window = SDL_CreateWindow("Arcade : SDL2", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_OPENGL);
    if (!_window) {
        std::cerr << "ERROR create window" << std::endl;
        exit(EXIT_FAILURE);
    }
    _renderer = SDL_CreateRenderer(_window, -1,
		SDL_RENDERER_ACCELERATED);
    if (!_renderer) {
        std::cerr << "ERROR surface window" << std::endl;
        exit(EXIT_FAILURE);
    }
    _surface = SDL_LoadBMP("Rscr/backgroundSDL.bmp");
    if (!_surface) {
        std::cerr << "ERROR _surface" << std::endl;
        exit(EXIT_FAILURE);
    }
    _texture = SDL_CreateTextureFromSurface(_renderer, _surface);
    if (!_texture) {
        std::cerr << "ERROR _texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (TTF_Init() < 0) {
        std::cerr << "ERROR ttf" << std::endl;
        exit(EXIT_FAILURE);
    }
    _font = TTF_OpenFont("Rscr/arial.ttf", 300);
    SDL_FreeSurface(_surface);
}

void SdlLib::destroyWindow()
{
	SDL_DestroyWindow(_window);
	_window = nullptr;
    TTF_Quit();
}

Arcade::Input SdlLib::getInput()
{
    SDL_Event _event;
    if (SDL_PollEvent(&_event) != 0) {
        if (_event.type == SDL_QUIT)
                return (Arcade::Input::F2);
        else if (_event.type == SDL_KEYDOWN) {
            switch (_event.key.keysym.sym) {
                case SDLK_LEFT :
                    return (Arcade::Input::LEFT);
                case SDLK_DOWN :
                    return (Arcade::Input::DOWN);
                case SDLK_UP :
                    return (Arcade::Input::UP); 
                case SDLK_RIGHT :
                    return (Arcade::Input::RIGHT);
                case SDLK_ESCAPE:
                    return (Arcade::Input::ESCAPE);
                case SDLK_BACKSPACE :
                    return (Arcade::Input::BACKSPACE);
                case SDLK_RETURN :
                    return (Arcade::Input::ENTER);
                case SDLK_a :
                    return (Arcade::Input::A_KEY);
                case SDLK_b :
                    return (Arcade::Input::B_KEY);
                case SDLK_c :
                    return (Arcade::Input::C_KEY);
                case SDLK_d :
                    return (Arcade::Input::D_KEY);
                case SDLK_e :
                    return (Arcade::Input::E_KEY);
                case SDLK_f :
                    return (Arcade::Input::F_KEY);
                case SDLK_g :
                    return (Arcade::Input::G_KEY);
                case SDLK_h :
                    return (Arcade::Input::H_KEY);
                case SDLK_i :
                    return (Arcade::Input::I_KEY);
                case SDLK_j :
                    return (Arcade::Input::J_KEY);
                case SDLK_k :
                    return (Arcade::Input::K_KEY);
                case SDLK_l :
                    return (Arcade::Input::L_KEY);
                case SDLK_m :
                    return (Arcade::Input::M_KEY);
                case SDLK_n :
                    return (Arcade::Input::N_KEY);
                case SDLK_o :
                    return (Arcade::Input::O_KEY);
                case SDLK_p :
                    return (Arcade::Input::P_KEY);
                case SDLK_q :
                    return (Arcade::Input::Q_KEY);
                case SDLK_r :
                    return (Arcade::Input::R_KEY);
                case SDLK_s :
                    return (Arcade::Input::S_KEY);
                case SDLK_t :
                    return (Arcade::Input::T_KEY);
                case SDLK_u :
                    return (Arcade::Input::U_KEY);
                case SDLK_v :
                    return (Arcade::Input::V_KEY);
                case SDLK_w :
                    return (Arcade::Input::W_KEY);
                case SDLK_x :
                    return (Arcade::Input::X_KEY);
                case SDLK_y :
                    return (Arcade::Input::Y_KEY);
                case SDLK_z :
                    return (Arcade::Input::Z_KEY);
                case SDLK_F2 :
                    return (Arcade::Input::F2);
                case SDLK_F3 :
                    return (Arcade::Input::F3);
                case SDLK_F4 :
                    return (Arcade::Input::F4);
                default :
                    return (Arcade::Input::NO_INPUT);
            }
        }
    }
    return (Arcade::Input::NO_INPUT);
}

void SdlLib::drawInterface()
{
    SDL_RenderClear(_renderer);
    SDL_RenderCopy(_renderer, _texture, NULL, NULL);
    setText("Arcade : SDL2 Graphics", 830, 150);
}


void SdlLib::display()
{
    SDL_RenderPresent(_renderer);
}

void SdlLib::setText(const std::string &string, const int &x, const int &y)
{
    SDL_Color color = {250, 250, 250, 250};
    SDL_Surface *surface = TTF_RenderText_Solid(_font, string.c_str(), color);
    if (!surface) {
        std::cerr << "ERROR text_surface" << std::endl;
        exit(EXIT_FAILURE);
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (!texture) {
        std::cerr << "ERROR text_texture" << std::endl;
        exit(EXIT_FAILURE);
    }
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = string.size() * 16;
	rect.h = 27;
    SDL_RenderCopy(_renderer, texture, nullptr, &rect);
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
}

void SdlLib::drawScreen(const std::string &screen)
{
    SDL_Texture *texture;

    texture = IMG_LoadTexture(_renderer, screen.c_str());
    SDL_RenderCopy(_renderer, texture, NULL, NULL);
	SDL_DestroyTexture(texture);
}

void SdlLib::drawPixel(const Arcade::Pixel &pixel)
{
    SDL_Texture *texture;
    SDL_Rect rect;
    rect.x = 410 + (22 * pixel.x);
    rect.y = 110 + (17 * pixel.y);
    rect.h = 22;
    rect.w = 22;
    texture = IMG_LoadTexture(_renderer,
			pixel.screenGame.c_str());
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
	SDL_DestroyTexture(texture);
}