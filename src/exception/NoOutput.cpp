/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoOutput.cpp
*/

#include "NoOutput.hpp"

NoOutput::NoOutput() {
    _what = "There is no output in the file";
}

const char *NoOutput::what() const noexcept {
    return _what.c_str();
}
