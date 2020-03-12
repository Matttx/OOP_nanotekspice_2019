/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_input.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_INPUT_HPP
#define OOP_NANOTEKSPICE_2019_C_INPUT_HPP

#include "SComponent.hpp"

namespace nts {
    class c_input: public SComponent {
    public:
        c_input(const std::string& name);
        nts::Tristate compute(size_t pin) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_C_INPUT_HPP
