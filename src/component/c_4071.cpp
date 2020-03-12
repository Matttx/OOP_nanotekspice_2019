/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** c_4071.cpp
*/

#include "c_4071.hpp"
#include "../gate/Or.hpp"

nts::c_4071::c_4071(const std::string& name) : Component(name, "4071") {
    initGate();
}

nts::Tristate nts::c_4071::compute(size_t pin) {
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
            for (auto ind : dynamic_cast<Or *>(i.first)->getInput())
                comp_int.insert(std::make_pair(ind.first, compute(ind.first)));
            return dynamic_cast<Or *>(i.first)->gate_operator(comp_int);
        }
    }
    return UNDEFINED;
}

void nts::c_4071::initGate() {
    std::vector<std::pair<Gate *, std::vector<size_t>>> gate;
    gate.push_back(std::pair<Or *, std::vector<size_t>>(new Or({1, 2}, {3}), {1, 2, 3}));
    gate.push_back(std::pair<Or *, std::vector<size_t>>(new Or({5, 6}, {4}), {4, 5, 6}));
    gate.push_back(std::pair<Or *, std::vector<size_t>>(new Or({8, 9}, {10}), {8, 9, 10}));
    gate.push_back(std::pair<Or *, std::vector<size_t>>(new Or({12, 13}, {11}), {11, 12, 13}));
    setGate(gate);
}