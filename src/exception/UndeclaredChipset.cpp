/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** UndeclaredChipset
*/

#include <iostream>
#include "UndeclaredChipset.hpp"

UndeclaredChipset::UndeclaredChipset(const std::string &name) {
    _what = "The chipset " + name + " is not declared in the .chipset part of the file";
}

const char *UndeclaredChipset::what() const noexcept {
    return _what.c_str();
}

