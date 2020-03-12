/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4081.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_4081_HPP
#define OOP_NANOTEKSPICE_2019_C_4081_HPP

#include "Component.hpp"

namespace nts {
    class c_4081: public Component {
    public:
        c_4081(const std::string& name);
        nts::Tristate compute(size_t pin) override;
        void initGate();
    };
}



#endif // OOP_NANOTEKSPICE_2019_C_4081_HPP
