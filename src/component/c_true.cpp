/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_true.cpp
*/

#include "c_true.hpp"

nts::c_true::c_true(const std::string &name) : SComponent(name, "true"){

}

nts::Tristate nts::c_true::compute(size_t pin) {
    (void) pin;
    return TRUE;
}
