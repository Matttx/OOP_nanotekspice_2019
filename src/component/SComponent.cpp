/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SComponent
*/

#include <iostream>
#include <utility>
#include "SComponent.hpp"

nts::SComponent::SComponent(const std::string &name, const std::string &type) : _name(name), _type(type), _pin(UNDEFINED){}

void nts::SComponent::dump() {
    std::cout << "Component:" << std::endl;
    std::cout << "Name: " << _name << std::endl;
    std::cout << "Type: " << _type << std::endl;
    std::cout << "Links:" << std::endl;
    std::cout << "\tPin 1 ";
    if (_link.first != nullptr)
        std::cout << "link to pin " << _link.second << " of component: " << _link.first->getName() << " type: " << _link.first->getType();
    std::cout << "\nValue: ";
    if (_pin == UNDEFINED)
        std::cout << "U" << std::endl;
    else {
        std::cout << _pin << std::endl;
    }
}

void nts::SComponent::setLink(size_t pin, IComponent &other, size_t otherPin) {
    (void) pin;
    _link = std::make_pair(&other, otherPin);
}

std::string nts::SComponent::getName() const {
    return _name;
}

const std::pair<nts::IComponent *, size_t> &nts::SComponent::getLink() const {
    return _link;
}

std::string nts::SComponent::getType() const {
    return _type;
}

nts::Tristate nts::SComponent::getPin() const {
    return _pin;
}

void nts::SComponent::setPin(nts::Tristate pin) {
    _pin = pin;
}