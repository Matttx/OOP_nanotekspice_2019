/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InputNoValue
*/

#include "InputNoValue.hpp"

InputNoValue::InputNoValue(const std::string &name)
{
    _what = "The input " + name + " is not initialized";
}

const char *InputNoValue::what() const noexcept {
    return _what.c_str();
}


