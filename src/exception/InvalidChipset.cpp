/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InvalidChipset
*/

#include "InvalidChipset.hpp"

InvalidChipset::InvalidChipset(const std::string &name) {
    _what = "The chipset " + name + " doesn't exist";
}

const char *InvalidChipset::what() const noexcept {
    return _what.c_str();
}

