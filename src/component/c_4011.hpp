/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4011.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_4011_HPP
#define OOP_NANOTEKSPICE_2019_C_4011_HPP

#include "Component.hpp"

namespace nts {
    class c_4011: public Component {
    public:
        c_4011(const std::string& name);
        nts::Tristate compute(size_t pin) override;
        void initGate();
    };
}



#endif // OOP_NANOTEKSPICE_2019_C_4011_HPP
