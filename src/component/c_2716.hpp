/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_2076.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_C_2076_HPP
#define OOP_NANOTEKSPICE_2019_C_2076_HPP

#include "Component.hpp"

namespace nts {
    class c_2716: public Component {
    public:
        explicit c_2716(const std::string& name);
        nts::Tristate compute(size_t pin) override;
    };
}



#endif // OOP_NANOTEKSPICE_2019_C_2076_HPP
