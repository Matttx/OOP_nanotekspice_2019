/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_clock.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_CLOCK_HPP
#define OOP_NANOTEKSPICE_2019_C_CLOCK_HPP

#include "SComponent.hpp"

namespace nts {
    class c_clock: public SComponent {
    public:
        c_clock(const std::string& name);
        nts::Tristate compute(size_t pin) override;
    };
}


#endif // OOP_NANOTEKSPICE_2019_C_CLOCK_HPP
