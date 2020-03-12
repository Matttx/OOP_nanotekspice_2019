/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4013.cpp
*/

#include "c_4013.hpp"

nts::c_4013::c_4013(const std::string& name) : Component(name, "4013"){
}

nts::Tristate nts::c_4013::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
