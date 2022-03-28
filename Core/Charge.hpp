/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-arcade-quentin.pages
** File description:
** Charge
*/

#ifndef CHARGE_HPP_
#define CHARGE_HPP_
#include "DLLoader.hpp"
#include "Core.hpp"

class Charge {
    public:
        Charge(const std::string &selected);
        ~Charge() = default;
        void start();

    protected:
    private:
        std::vector<std::shared_ptr<DLLoader<IDisplayModule>>> _libraries;
        std::vector<std::shared_ptr<DLLoader<IGames>>> _games;
        std::unique_ptr<Core> _core;
        std::string _selected;
        int _libInd;
};

#endif /* !CHARGE_HPP_ */
