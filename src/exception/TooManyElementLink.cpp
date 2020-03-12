/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TooManyElementLink
*/

#include "TooManyElementLink.hpp"
#include <iostream>

TooManyElementLink::TooManyElementLink(const std::string &name, size_t size) {
    if (size < 2)
         _what = "There is not enough elements in the line containing : " + name;
    else
        _what = "There is too many elements in the line containing : " + name;
}

const char *TooManyElementLink::what() const noexcept {
    return _what.c_str();
}
