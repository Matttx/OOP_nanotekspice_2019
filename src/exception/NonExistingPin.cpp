/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NonExistingPin
*/

#include <iostream>
#include "NonExistingPin.hpp"

NonExistingPin::NonExistingPin(const std::string &pin_number, const std::string &comp_name) {
    _what = "The pin " + pin_number + " does not exist in component " + comp_name;
}

const char *NonExistingPin::what() const noexcept {
    return _what.c_str();
}
