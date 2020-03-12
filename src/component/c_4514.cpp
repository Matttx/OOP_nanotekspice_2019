/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4514.cpp
*/

#include "c_4514.hpp"

nts::c_4514::c_4514(const std::string& name) : Component(name, "4514"){
}

nts::Tristate nts::c_4514::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
