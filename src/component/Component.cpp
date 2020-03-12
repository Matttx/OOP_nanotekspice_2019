/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component.cpp
*/

#include <iostream>
#include <utility>
#include "Component.hpp"

nts::Component::Component(const std::string &name, const std::string &type) : _name(name), _type(type) {}

void nts::Component::dump() {
    auto j = _gate.begin();
    std::cout << "Component:" << std::endl;
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Type: " << _type << std::endl;
    std::cout << "Gates:" << std::endl;
    std::cout << "\ttype: " << j->first->getType()<< std::endl;
    std::cout << "Links:" << std::endl;
    for (auto &i : _link)
        std::cout << "\tPin " << i.first << " link to pin " << i.second.second << " of component: " << i.second.first->getName() << " type: " << i.second.first->getType() << std::endl;
}

void nts::Component::setLink(size_t pin, IComponent &other, size_t otherPin) {
    _link[pin] = std::make_pair(&other, otherPin);
}

std::string nts::Component::getName() const {
    return _name;
}

const std::map<size_t, std::pair<nts::IComponent *, size_t>> &nts::Component::getLink() const {
    return _link;
}

const std::vector<std::pair<nts::Gate *, std::vector<size_t>>> &nts::Component::getGate() const {
    return _gate;
}

void nts::Component::setGate(std::vector<std::pair<Gate *, std::vector<size_t>>> gate) {
    _gate = std::move(gate);
}

std::string nts::Component::getType() const {
    return _type;
}