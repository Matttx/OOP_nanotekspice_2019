/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** LinkWrongFormat
*/

#include "LinkWrongFormat.hpp"

LinkWrongFormat::LinkWrongFormat(const std::string &name) {
    _what = "The link on the line " + name + " is badly formatted";
}

const char *LinkWrongFormat::what() const noexcept {
    return _what.c_str();
}
