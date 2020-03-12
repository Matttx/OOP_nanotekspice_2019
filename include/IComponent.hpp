/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** IComponent.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP

#include <string>

namespace nts {
    enum Tristate {
        UNDEFINED = -true,
        TRUE = true,
        FALSE = false
    };
    class IComponent {
    public:
        ~IComponent() = default;
        virtual nts::Tristate compute(size_t pin) = 0;
        virtual void setLink(size_t pin, IComponent &other, size_t otherPin) = 0;
        virtual void dump() = 0;
        virtual std::string getName() const = 0;
        virtual std::string getType() const = 0;
    };
}


#endif // OOP_NANOTEKSPICE_2019_ICOMPONENT_HPP
