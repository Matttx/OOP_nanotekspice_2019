/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4008.cpp
*/

#include "c_4008.hpp"

nts::c_4008::c_4008(const std::string& name) : Component(name, "4008") {
}

nts::Tristate nts::c_4008::compute(size_t pin) {
    (void) pin;
    return TRUE;
}