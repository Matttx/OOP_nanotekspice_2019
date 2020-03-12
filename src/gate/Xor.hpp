/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Xor.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_XOR_HPP
#define OOP_NANOTEKSPICE_2019_XOR_HPP

#include "Gate.hpp"

namespace nts {
    class Xor : public Gate{
    public:
        Xor(std::vector<size_t> input, std::vector<size_t> output);
        Tristate gate_operator(const std::map<size_t, Tristate>& _input) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_XOR_HPP
