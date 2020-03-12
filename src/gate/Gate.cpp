/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gate.cpp
*/

#include <utility>
#include <vector>
#include "Gate.hpp"

std::map<size_t, nts::Tristate> nts::Gate::getInput() const {
    return _input;
}

nts::Tristate nts::Gate::getInput(size_t pin) const {
    if (pin > _input.size())
        return UNDEFINED;
    else
        return _input.at(pin);
}

std::map<size_t, nts::Tristate> nts::Gate::getOutput() const {
    return _output;
}

nts::Tristate nts::Gate::getOutput(size_t pin) const {
    if (pin > _output.size())
        return UNDEFINED;
    else
        return _input.at(pin);
}

void nts::Gate::setInput(size_t pin, nts::Tristate value) {
    auto i = _input.find(pin);
    if (i != _input.end())
        i->second = value;
    else
        _input.insert(std::pair<size_t, nts::Tristate>(pin, value));
}

void nts::Gate::setOutput(size_t pin, nts::Tristate value) {
    auto i = _output.find(pin);
    if (i != _output.end())
        i->second = value;
    else
        _output.insert(std::pair<size_t, nts::Tristate>(pin, value));
}

std::map<size_t, nts::Tristate> setMap(std::vector<size_t> values) {
    std::map<size_t, nts::Tristate> map;

    for (auto & i : values)
        map.insert(std::pair<size_t, nts::Tristate>(i, nts::UNDEFINED));
    return map;
}

nts::Gate::Gate(std::vector<size_t> input, std::vector<size_t> output, std::string type) {
    _input = setMap(std::move(input));
    _output = setMap(std::move(output));
    _type = type;
}

std::string nts::Gate::getType() {
    return _type;
}
