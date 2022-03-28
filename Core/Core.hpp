/*
** EPITECH PROJECT, 2021
** Boostrap_Arcade
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include "DLLoader.hpp"
#include "../Graphicals/IDisplayModule.hpp"
#include "../Games/IGames.hpp"
#include "utility"
#include "Input.hpp"
#include <string>

class Core {
    public:
        Core(std::vector<std::shared_ptr<DLLoader<IDisplayModule>>> libraries,
            std::vector<std::shared_ptr<DLLoader<IGames>>> games,
            int libInd);
        ~Core() = default;
        void loop();
        void keyEvents(const Arcade::Input &input);
        void Menu(Arcade::Input &input);
        void startGame(Arcade::Input &input);
        void directionGame(bool direction);
        void directionLibrary(bool direction);
        void printLibraries();
        void drawAllGame(const std::vector<std::vector<Arcade::Pixel>> &all);

    protected:
    private:
        std::vector<std::shared_ptr<DLLoader<IDisplayModule>>> _libraries;
        std::vector<std::shared_ptr<DLLoader<IGames>>> _games;
        int _libInd;
        std::shared_ptr<DLLoader<IDisplayModule>> _currentLib;
        int _gamesInd;
        std::shared_ptr<DLLoader<IGames>> _currentGames;
        bool _quit;
        bool _menu;
        std::string _name;
};

#endif /* !CORE_HPP_ */