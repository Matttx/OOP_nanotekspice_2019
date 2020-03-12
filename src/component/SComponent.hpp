/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SComponent
*/

#ifndef SCOMPONENT_HPP_
#define SCOMPONENT_HPP_

#include <string>
#include <functional>
#include <map>
#include <memory>
#include <vector>
#include "IComponent.hpp"

namespace nts {
    class SComponent : public IComponent {
        public:
            SComponent(const std::string &name, const std::string &type);
            nts::Tristate compute(size_t pin) = 0;
            void setLink(size_t pin, IComponent &other, size_t otherPin) override;
            void dump() override;
            std::string getName() const override;
            std::string getType() const override;
            const std::pair<IComponent *, size_t> &getLink() const;
            Tristate getPin() const;
            void setPin(Tristate pin);
        protected:
        private:
            std::string _name;
            std::string _type;
            std::pair<nts::IComponent *, size_t> _link;
            nts::Tristate _pin;
    };
}

#endif /* !SCOMPONENT_HPP_ */
