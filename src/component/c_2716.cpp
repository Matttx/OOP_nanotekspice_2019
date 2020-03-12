/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_2076.cpp
*/

#include "c_2716.hpp"

nts::c_2716::c_2716(const std::string& name) : Component(name, "2716") {
}

nts::Tristate nts::c_2716::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
