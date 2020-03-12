/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Not.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NOT_HPP
#define OOP_NANOTEKSPICE_2019_NOT_HPP

#include <vector>
#include "Gate.hpp"

namespace nts {
    class Not : public Gate {
    public:
        Not(std::vector<size_t> input, std::vector<size_t> output);
        Tristate gate_operator(const std::map<size_t, Tristate>& _input);
    };
}


#endif // OOP_NANOTEKSPICE_2019_NOT_HPP
