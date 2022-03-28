/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_
#include "../IGames.hpp"

class Nibbler : public IGames
{
    public:
        Nibbler();
        ~Nibbler() = default;
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
        void apple();
        const int &getScore() const;

    protected:
    private:
        std::string _name;
        std::vector<Arcade::Pixel> _pixel;
        std::vector<Arcade::Pixel> _snake;
        std::vector<Arcade::Pixel> _apple;
        Arcade::Input _up;
        Arcade::Input _down;
        Arcade::Input _left;
        Arcade::Input _right;
        Arcade::Input _currentInput;
        Arcade::Input _check;
        Arcade::Input _restart;
        int _score;
};

#endif /* !NIBBLER_HPP_ */
