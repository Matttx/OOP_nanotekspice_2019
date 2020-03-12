/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4094.cpp
*/

#include "c_4094.hpp"

nts::c_4094::c_4094(const std::string& name) : Component(name, "4094") {
}

nts::Tristate nts::c_4094::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
