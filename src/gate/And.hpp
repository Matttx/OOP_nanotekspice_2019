/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** And.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_AND_HPP
#define OOP_NANOTEKSPICE_2019_AND_HPP

#include <vector>
#include "Gate.hpp"

namespace nts {
    class And : public Gate {
    public:
        And(std::vector<size_t> input, std::vector<size_t> output);
        Tristate gate_operator(const std::map<size_t, Tristate>& _input) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_AND_HPP
