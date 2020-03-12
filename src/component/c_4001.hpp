/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** component_4001.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_COMPONENT_4001_HPP
#define OOP_NANOTEKSPICE_2019_COMPONENT_4001_HPP

#include "Component.hpp"

namespace nts {
    class c_4001: public Component {
    public:
        c_4001(const std::string& name);
        nts::Tristate compute(size_t pin) override;
        void initGate();
    };
}



#endif // OOP_NANOTEKSPICE_2019_COMPONENT_4001_HPP
