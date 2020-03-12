/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_clock.cpp
*/

#include "c_clock.hpp"

nts::c_clock::c_clock(const std::string& name) : SComponent(name, "clock"){
}


nts::Tristate nts::c_clock::compute(size_t pin) {
    (void) pin;
    return getPin();
}
