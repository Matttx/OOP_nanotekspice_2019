/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Nand.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NAND_HPP
#define OOP_NANOTEKSPICE_2019_NAND_HPP

#include <vector>
#include "Gate.hpp"

namespace nts {
    class Nand : public Gate {
    public:
        Nand(std::vector<size_t> input, std::vector<size_t> output);
        Tristate gate_operator(const std::map<size_t, Tristate>& _input);
    };
}

#endif // OOP_NANOTEKSPICE_2019_NAND_HPP
