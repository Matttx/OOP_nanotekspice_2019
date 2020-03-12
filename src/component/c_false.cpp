/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_false.cpp
*/

#include "c_false.hpp"

nts::c_false::c_false(const std::string& name) : SComponent(name, "false"){
}

nts::Tristate nts::c_false::compute(size_t pin) {
    (void) pin;
    return FALSE;
}
