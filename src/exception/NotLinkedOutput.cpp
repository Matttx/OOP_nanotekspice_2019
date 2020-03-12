/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NotLinkedOutput.cpp
*/

#include "NotLinkedOutput.hpp"

NotLinkedOutput::NotLinkedOutput(const std::string &name) {
    _what = "The output " + name + " is not linked to anything";
}

const char *NotLinkedOutput::what() const noexcept {
    return _what.c_str();
}