/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SameChipsetName
*/

#include <iostream>
#include "SameChipsetName.hpp"

SameChipsetName::SameChipsetName(const std::string &name) {
    _what = "There are more than one chipset named " + name + " in the .chipset part of the file";
}

const char *SameChipsetName::what() const noexcept {
    return _what.c_str();
}
