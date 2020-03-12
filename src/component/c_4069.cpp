/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4069.cpp
*/

#include "c_4069.hpp"
#include "../gate/Not.hpp"

nts::c_4069::c_4069(const std::string& name) : Component(name, "4069"){
    initGate();
}

nts::Tristate nts::c_4069::compute(size_t pin) {
    auto gate = getGate();
    auto link = getLink();
    std::map<size_t, Tristate> comp_int;

    for (auto & i : gate) {
        auto input = i.first->getInput();
        auto output = i.first->getOutput();
        if (input.find(pin) != input.end()) {
            auto find_pin = link.find(pin);
            return find_pin->second.first->compute(find_pin->second.second);
        }
        if (output.find(pin) != output.end()) {
            for (auto ind : dynamic_cast<Not *>(i.first)->getInput())
                comp_int.insert(std::make_pair(ind.first, compute(ind.first)));
            return dynamic_cast<Not *>(i.first)->gate_operator(comp_int);
        }
    }
    return UNDEFINED;
}

void nts::c_4069::initGate() {
    std::vector<std::pair<Gate *, std::vector<size_t>>> gate;
    gate.push_back(std::pair<Not *, std::vector<size_t>>(new Not({1}, {2}), {1, 2}));
    gate.push_back(std::pair<Not *, std::vector<size_t>>(new Not({3}, {4}), {3, 4}));
    gate.push_back(std::pair<Not *, std::vector<size_t>>(new Not({5}, {6}), {5, 6}));
    gate.push_back(std::pair<Not *, std::vector<size_t>>(new Not({9}, {8}), {9, 8}));
    gate.push_back(std::pair<Not *, std::vector<size_t>>(new Not({11}, {10}), {11, 10}));
    gate.push_back(std::pair<Not *, std::vector<size_t>>(new Not({13}, {12}), {13, 12}));
    setGate(gate);
}