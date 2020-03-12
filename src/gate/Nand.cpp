/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Nand.cpp
*/

#include "Nand.hpp"

nts::Nand::Nand(std::vector<size_t> input, std::vector<size_t> output) : Gate(std::move(input), std::move(output), "Nand") {}

nts::Tristate nts::Nand::gate_operator(const std::map<size_t, Tristate> &_input) {
    Tristate res = UNDEFINED;
    int count = 0;

    for (auto &i : _input) {
        if (count == 0) {
            res = i.second;
            count++;
        }
        else {
            if ((res == UNDEFINED && i.second == TRUE) || (res == TRUE && i.second == UNDEFINED))
                res = UNDEFINED;
            else if ((res == FALSE && i.second == TRUE) || (res == TRUE && i.second == FALSE) ||
                (res == FALSE && i.second == FALSE) || (res == UNDEFINED && i.second == FALSE) ||
                (res == FALSE && i.second == UNDEFINED))
                res = TRUE;
            else
                res = FALSE;
        }
    }
    return res;
}
