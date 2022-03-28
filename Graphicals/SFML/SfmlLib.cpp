/*
** EPITECH PROJECT, 2021
** Arcade
** File description:
** SfmlLib
*/

#include "SfmlLib.hpp"

extern "C" {
    IDisplayModule *entryPoint()
    {
        return (new SfmlLib());
    }
}

SfmlLib::SfmlLib() : _name("SfmlLib") {}

void SfmlLib::createWindow()
{
    _window.create(sf::VideoMode(1920, 1080), "Arcade - SFML",
        sf::Style::Resize | sf::Style::Close);
    if (!_font.loadFromFile("Rscr/arial.ttf"))
    {
        std::cerr << "ERROR arial.ttf" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (!_texture.loadFromFile("Rscr/backgroundSFML.png"))
        exit(EXIT_FAILURE);
    _sprite.setTexture(_texture);
}

const std::string &SfmlLib::getName() const
{
    return (_name);
}

Arcade::Input SfmlLib::getInput()
{
    sf::Event event;
    if (!_window.pollEvent(event))
        return (Arcade::Input::NO_INPUT);
    if (event.type == sf::Event::Closed)
        return (Arcade::Input::F2);
    if (event.type == sf::Event::KeyPressed) {
		switch (event.key.code) {
		case sf::Keyboard::F2 :
			return Arcade::Input::F2;
        case sf::Keyboard::F3 :
            return Arcade::Input::F3;
        case sf::Keyboard::F4 :
            return Arcade::Input::F4;
        case sf::Keyboard::Left :
            return Arcade::Input::LEFT;
        case sf::Keyboard::Right :
            return Arcade::Input::RIGHT;
        case sf::Keyboard::Up :
            return Arcade::Input::UP;
        case sf::Keyboard::Down :
            return Arcade::Input::DOWN;
        case sf::Keyboard::BackSpace :
            return Arcade::Input::BACKSPACE;
        case sf::Keyboard::Return :
            return Arcade::Input::ENTER;
        case sf::Keyboard::A :
            return Arcade::Input::A_KEY;
        case sf::Keyboard::B :
            return Arcade::Input::B_KEY;
        case sf::Keyboard::C :
            return Arcade::Input::C_KEY;
        case sf::Keyboard::D :
            return Arcade::Input::D_KEY;
        case sf::Keyboard::E :
            return Arcade::Input::E_KEY;
        case sf::Keyboard::F :
            return Arcade::Input::F_KEY;
        case sf::Keyboard::G :
            return Arcade::Input::G_KEY;
        case sf::Keyboard::H :
            return Arcade::Input::H_KEY;
        case sf::Keyboard::I :
            return Arcade::Input::I_KEY;
        case sf::Keyboard::J :
            return Arcade::Input::J_KEY;
        case sf::Keyboard::K :
            return Arcade::Input::K_KEY;
        case sf::Keyboard::L :
            return Arcade::Input::L_KEY;
        case sf::Keyboard::M :
            return Arcade::Input::M_KEY;
        case sf::Keyboard::N :
            return Arcade::Input::N_KEY;
        case sf::Keyboard::O :
            return Arcade::Input::O_KEY;
        case sf::Keyboard::P :
            return Arcade::Input::P_KEY;
        case sf::Keyboard::Q :
            return Arcade::Input::Q_KEY;
        case sf::Keyboard::R :
            return Arcade::Input::R_KEY;
        case sf::Keyboard::S :
            return Arcade::Input::S_KEY;
        case sf::Keyboard::T :
            return Arcade::Input::T_KEY;
        case sf::Keyboard::U :
            return Arcade::Input::U_KEY;
        case sf::Keyboard::V :
            return Arcade::Input::V_KEY;
        case sf::Keyboard::W :
            return Arcade::Input::W_KEY;
        case sf::Keyboard::X :
            return Arcade::Input::X_KEY;
        case sf::Keyboard::Y :
            return Arcade::Input::Y_KEY;
        case sf::Keyboard::Z :
            return Arcade::Input::Z_KEY;
        case sf::Keyboard::Escape :
            return Arcade::Input::ESCAPE;
        default :
            return Arcade::Input::NO_INPUT;
        }
    }
    return (Arcade::Input::NO_INPUT);
}

void SfmlLib::drawInterface()
{
    _window.clear(sf::Color::Black);
    _sprite.setTexture(_texture);
    _window.draw(_sprite);
    setText("Arcade : SFML Graphics", 800, 150);
}

void SfmlLib::destroyWindow()
{
   _window.close();
}

void SfmlLib::setText(const std::string &string, const int &x, const int &y)
{
    sf::Text text;

    text.setFont(_font);
    text.setPosition(x, y);
    text.setString(string);
    text.setCharacterSize(28);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    _window.draw(text);
}

void SfmlLib::display()
{
    _window.display();
}

void SfmlLib::drawScreen(const std::string &screen)
{
    sf::Texture texture;
    texture.loadFromFile(screen);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    _window.draw(sprite);
}

void SfmlLib::drawPixel(const Arcade::Pixel &pixel)
{
    auto x = 410 + (22 * pixel.x);
    auto y = 110 + (17 * pixel.y);
    sf::Texture texture;
    texture.loadFromFile(pixel.screenGame);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    _window.draw(sprite);
}