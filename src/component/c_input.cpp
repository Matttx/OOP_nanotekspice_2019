/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_input.cpp
*/

#include "c_input.hpp"

nts::c_input::c_input(const std::string& name) : SComponent(name, "input"){
}

nts::Tristate nts::c_input::compute(size_t pin) {
    (void) pin;
    return getPin();
}
