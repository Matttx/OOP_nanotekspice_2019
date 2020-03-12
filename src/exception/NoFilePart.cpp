/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoFilePart
*/

#include <iostream>
#include "NoFilePart.hpp"

NoFilePart::NoFilePart(const std::string &name) {
    _what = "The line " + name + " is missing in the file";
}

const char *NoFilePart::what() const noexcept {
    return _what.c_str();
}
