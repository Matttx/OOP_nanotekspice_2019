/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** nts::Component.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_COMPONENT_HPP
#define OOP_NANOTEKSPICE_2019_COMPONENT_HPP

#include <string>
#include <functional>
#include <map>
#include <memory>
#include <vector>
#include "IComponent.hpp"
#include "../gate/Gate.hpp"

namespace nts {
    class Component: public IComponent {
    public:
        Component(const std::string &name, const std::string &type);
        void setLink(size_t pin, IComponent &other, size_t otherPin) override;
        const std::map<size_t, std::pair<IComponent *, size_t>> &getLink() const;
        const std::vector<std::pair<Gate *, std::vector<size_t>>> &getGate() const;
        void setGate(std::vector<std::pair<Gate  *, std::vector<size_t>>> gate);
        void dump() override;
        std::string getName() const override;
        std::string getType() const override;
    private:
        std::vector<std::pair<nts::Gate *, std::vector<size_t>>> _gate;
        std::map<size_t, std::pair<IComponent *, size_t>> _link;
        std::string _name;
        std::string _type;
    };
}

#endif // OOP_NANOTEKSPICE_2019_COMPONENT_HPP

