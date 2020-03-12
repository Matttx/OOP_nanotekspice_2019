/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4071.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_4071_HPP
#define OOP_NANOTEKSPICE_2019_C_4071_HPP

#include "Component.hpp"

namespace nts {
    class c_4071: public Component {
    public:
        c_4071(const std::string& name);
        nts::Tristate compute(size_t pin) override;
        void initGate();
    };
}



#endif // OOP_NANOTEKSPICE_2019_C_4071_HPP
