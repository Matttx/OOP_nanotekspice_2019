/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Xor.cpp
*/

#include "Xor.hpp"

#include <utility>

nts::Xor::Xor(std::vector<size_t> input, std::vector<size_t> output) : Gate(std::move(input), std::move(output), "Xor") {}

nts::Tristate nts::Xor::gate_operator(const std::map<size_t, nts::Tristate>& _input) {
    Tristate res = UNDEFINED;
    int count = 0;

    for (auto &i : _input) {
        if (count == 0) {
            res = i.second;
            count++;
        }
        else {
            if (res == UNDEFINED || i.second == UNDEFINED)
                return UNDEFINED;
            if (res == i.second)
                res = FALSE;
            else
                res = TRUE;
        }
    }
    return res;
}
