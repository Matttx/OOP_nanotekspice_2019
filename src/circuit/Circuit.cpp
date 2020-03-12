/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.cpp
*/

#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include "Circuit.hpp"
#include "../parser/parser.hpp"
#include "../component/c_output.hpp"
#include "../exception/UndeclaredChipset.hpp"

Circuit::Circuit(const std::vector<std::string>& chipset, const std::vector<std::string>& link, char **argv) {
    std::vector<std::string> tmp;
    std::vector<std::string> comp;
    std::vector<std::string> comp2;
    nts::IComponent *component;
    nts::IComponent *component2;
    int value = 0;

    for (const auto & i : chipset) {
       tmp = split(i, ' ');
       auto it = COMPONENT_CONSTRUCTOR.find(tmp[0]);
       setComponent(it->second(tmp[1]));
    }
    for (const auto & i : link) {
        tmp = split(i, ' ');
        if (tmp.size() != 2)
            std::exit(84);
        comp = split(tmp[0], ':');
        if (comp.size() != 2)
            std::exit(84);
        comp2 = split(tmp[1], ':');
        if (comp2.size() != 2)
            std::exit(84);
        component = getComp(comp2[0]);
        component2 = getComp(comp[0]);
        if (component2->getType() == "output")
            component2->setLink(atoi(comp[1].c_str()), *component, atoi(comp2[1].c_str()));
        else
            component->setLink(atoi(comp2[1].c_str()), *component2, atoi(comp[1].c_str()));
    }
    for (size_t j = 2; argv[j]; j++) {
        std::string tmp_val(argv[j]);
        std::vector<std::string> pin_value = split(tmp_val, '=');
        component = getComp(pin_value[0]);
        if (component == nullptr)
            throw(UndeclaredChipset(pin_value[0]));
        value = atoi(pin_value[1].c_str());
        if (value == 1)
            static_cast<nts::c_input *>(component)->setPin(nts::TRUE);
        else if (value == 0)
            static_cast<nts::c_input *>(component)->setPin(nts::FALSE);
        else {
            std::exit(84);
        }
    }
}

nts::IComponent *Circuit::getComp(const std::string &name) const {
    for (const auto & i : _comp)
        if (i->getName() == name)
            return i.get();
    return nullptr;
}

nts::IComponent *Circuit::getComp(size_t pos) const {
    if (pos > _comp.size())
        return nullptr;
    return _comp[pos].get();
}

void Circuit::setComponent(std::unique_ptr<nts::IComponent> comp) {
    _comp.push_back(std::move(comp));
}

std::vector<nts::IComponent *> Circuit::getComp() const {
    std::vector<nts::IComponent *> comp_vec;
    for (const auto & i : _comp) {
        comp_vec.push_back(i.get());
    }
    return comp_vec;
}

void Circuit::dump() {
    auto comp = getComp();

    for (auto &i : comp) {
        i->dump();
        std::cout << std::endl;
    }
}

void Circuit::exit() {
    std::exit(0);
}

bool sortByVal(const std::pair<std::string, int> &a, const std::pair<std::string, int> &b) {
    return (a.first < b.first);
}

void Circuit::display() {
    std::vector<std::pair<std::string, size_t>> vec;
    for (auto &i : _comp) {
        auto output = dynamic_cast<nts::c_output *>(i.get());
        if (output)
            vec.push_back(std::make_pair(output->getName(), output->getPin()));
    }
    std::sort(vec.begin(), vec.end(), sortByVal);
    for (auto &i : vec) {
        if (i.second != 1 && i.second != 0)
            std::cout << i.first << "=U" << std::endl;
        else
            std::cout << i.first << "=" << i.second << std::endl;
    }
}

void Circuit::loop() {
    std::string command;
    while (1) {
        simulate();
        display();
    }
}

void Circuit::simulate() {
    for (auto &i : _comp) {
        auto output = dynamic_cast<nts::c_output *>(i.get());
        if (output)
            output->setPin(output->compute(output->getPin()));
    }
    manage_clock();
}

void Circuit::setValue(std::vector<std::string> vec) {
    auto i = getComp(vec[0]);
    auto value = atoi(vec[1].c_str());

    if (i == nullptr) {
        std::cerr << "The component " << vec[0] << " does not exist" << std::endl;
        return;
    }
    if (i->getType() != "input" && i->getType() != "clock") {
        std::cerr << "The component " << vec[0] << " is not a clock or an input" << std::endl;
        return;
    }
    if (value == 1) {
        if (i->getType() == "input")
            dynamic_cast<nts::c_input *>(i)->setPin(nts::TRUE);
        else if (i->getType() == "clock")
            dynamic_cast<nts::c_clock *>(i)->setPin(nts::TRUE);
        }
    else if (value == 0) {
        if (i->getType() == "input")
            dynamic_cast<nts::c_input *>(i)->setPin(nts::FALSE);
        else if (i->getType() == "clock")
            dynamic_cast<nts::c_clock *>(i)->setPin(nts::FALSE);
    }
    else {
        std::cerr << "Please choose a value between 0 and 1" << std::endl;
        return;
    }
}

void Circuit::manage_clock() {
    nts::Tristate val;

    for (auto &i : _comp) {
        if (i->getType() == "clock") {
            val = dynamic_cast<nts::c_clock *>(i.get())->getPin();
            if (val == nts::TRUE)
                static_cast<nts::c_clock *>(i.get())->setPin(nts::FALSE);
            else
                static_cast<nts::c_clock *>(i.get())->setPin(nts::TRUE);
        }
    }
}