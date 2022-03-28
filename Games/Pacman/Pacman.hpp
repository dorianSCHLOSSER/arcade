/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_
#include "../IGames.hpp"

class Pacman : public IGames
{
    public:
        Pacman();
        ~Pacman() = default;
        const std::string &getName() const;
        std::string getScreen();
        void start();
        std::vector<std::vector<Arcade::Pixel>> getAllPixel();
        void getInput(const Arcade::Input &input);
        void up();
        void down();
        void left();
        void right();
        void move();
        void point();
        const int &getScore() const;

    protected:
    private:
        std::string _name;
        std::vector<Arcade::Pixel> _pixel;
        std::vector<Arcade::Pixel> _pacman;
        std::vector<Arcade::Pixel> _point;
        std::vector<Arcade::Pixel> _ghosts;
        Arcade::Input _up;
        Arcade::Input _down;
        Arcade::Input _left;
        Arcade::Input _right;
        Arcade::Input _currentInput;
        Arcade::Input _check;
        Arcade::Input _restart;
        int _score;
};

#endif /* !PACMAN_HPP_ */
