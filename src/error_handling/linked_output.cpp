/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** linked_output.cpp
*/

#include "../circuit/Circuit.hpp"
#include "../component/SComponent.hpp"
#include "../exception/NoOutput.hpp"
#include "../exception/NotLinkedOutput.hpp"

void linked_output(Circuit &circuit) {
    std::vector<nts::IComponent *> comp = circuit.getComp();
    std::pair <nts::IComponent *, size_t> link;
    bool is_output = false;

    for (const auto & i : comp) {
        if (i->getType() == "output") {
            link = static_cast<nts::c_output *>(i)->getLink();
            is_output = true;
            if (link.first == nullptr)
                throw(NotLinkedOutput(i->getName()));
        }
    }
    if (!is_output)
        throw(NoOutput());
}