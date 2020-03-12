/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4801.cpp
*/

#include "c_4801.hpp"

nts::c_4801::c_4801(const std::string& name) : Component(name, "4801"){
}

nts::Tristate nts::c_4801::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
