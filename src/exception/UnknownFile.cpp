/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** UnknownFile
*/

#include <iostream>
#include "UnknownFile.hpp"

UnknownFile::UnknownFile(const std::string &name) {
    _what = "Cannot open file " + name;
}

const char *UnknownFile::what() const noexcept {
    return _what.c_str();
}

