/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** input_value
*/

#include "../circuit/Circuit.hpp"
#include "../exception/InputNoValue.hpp"

void verif_input_val(Circuit &circuit)
{
    std::vector<nts::IComponent *> comp = circuit.getComp();

    for (auto & i : comp) {
        if (i->getType() == "clock" || i->getType() == "input") {
            if (static_cast<nts::c_clock *>(i)->getPin() == nts::UNDEFINED)
                throw (InputNoValue(i->getName()));
        }
    }
}