/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Not.cpp
*/

#include "Not.hpp"

#include <utility>

nts::Not::Not(std::vector<size_t> input, std::vector<size_t> output) : Gate(std::move(input), std::move(output), "Not") {}

nts::Tristate nts::Not::gate_operator(const std::map<size_t, Tristate>& _input) {
    auto i = _input.begin();

    if (i->second == UNDEFINED)
        return UNDEFINED;
    if (i->second == TRUE)
        return FALSE;
    else
        return TRUE;
}