/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_output.cpp
*/

#include "c_output.hpp"

nts::c_output::c_output(const std::string& name) : SComponent(name, "output"){
}

nts::Tristate nts::c_output::compute(size_t pin) {
    (void) pin;
    Tristate val;
    auto link = getLink();
    val = link.first->compute(link.second);
    setPin(val);
    return val;
}
