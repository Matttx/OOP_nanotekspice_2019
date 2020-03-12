/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Or.cpp
*/

#include "Or.hpp"

#include <utility>

nts::Or::Or(std::vector<size_t> input, std::vector<size_t> output) : Gate(std::move(input), std::move(output), "Or") {}

nts::Tristate nts::Or::gate_operator(const std::map<size_t, Tristate>& _input) {
    Tristate res = UNDEFINED;
    int count = 0;

    for (auto &i : _input) {
        if (count == 0) {
            res = i.second;
            count++;
        }
        else {
            if ((res == UNDEFINED && i.second == FALSE) || (res == FALSE && i.second == UNDEFINED) || (res == UNDEFINED && i.second == UNDEFINED))
                res = UNDEFINED;
            else if (res == FALSE && i.second == FALSE)
                res = FALSE;
            else
                res = TRUE;
        }
    }
    return res;
}
