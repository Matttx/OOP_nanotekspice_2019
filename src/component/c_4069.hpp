/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4069.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_4069_HPP
#define OOP_NANOTEKSPICE_2019_C_4069_HPP

#include "Component.hpp"

namespace nts {
    class c_4069: public Component {
    public:
        c_4069(const std::string& name);
        nts::Tristate compute(size_t pin) override;
        void initGate();
    };
}



#endif // OOP_NANOTEKSPICE_2019_C_4069_HPP
