/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4040.cpp
*/

#include "c_4040.hpp"

nts::c_4040::c_4040(const std::string& name) : Component(name, "4040"){
}

nts::Tristate nts::c_4040::compute(size_t pin) {
    (void) pin;
    return TRUE;
}