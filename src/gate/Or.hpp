/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Or.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_OR_HPP
#define OOP_NANOTEKSPICE_2019_OR_HPP

#include <vector>
#include "Gate.hpp"

namespace nts {
    class Or : public Gate {
    public:
        Or(std::vector<size_t> input, std::vector<size_t> output);
        Tristate gate_operator(const std::map<size_t, Tristate>& _input) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_OR_HPP
