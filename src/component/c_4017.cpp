/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4017.cpp
*/

#include "c_4017.hpp"

nts::c_4017::c_4017(const std::string& name) : Component(name, "4017"){
}

nts::Tristate nts::c_4017::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
