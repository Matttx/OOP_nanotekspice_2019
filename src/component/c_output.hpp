/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_output.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_OUTPUT_HPP
#define OOP_NANOTEKSPICE_2019_C_OUTPUT_HPP

#include "SComponent.hpp"

namespace nts {
    class c_output: public SComponent {
    public:
        c_output(const std::string& name);
        nts::Tristate compute(size_t pin) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_C_OUTPUT_HPP
