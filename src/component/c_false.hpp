/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_false.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_FALSE_HPP
#define OOP_NANOTEKSPICE_2019_C_FALSE_HPP

#include "SComponent.hpp"

namespace nts {
    class c_false: public SComponent {
    public:
        c_false(const std::string& name);
        nts::Tristate compute(size_t pin) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_C_FALSE_HPP
