/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_true.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_TRUE_HPP
#define OOP_NANOTEKSPICE_2019_C_TRUE_HPP

#include "SComponent.hpp"

namespace nts {
    class c_true: public SComponent {
    public:
        c_true(const std::string& name);
        nts::Tristate compute(size_t pin) override;
    };
}

#endif // OOP_NANOTEKSPICE_2019_C_TRUE_HPP
