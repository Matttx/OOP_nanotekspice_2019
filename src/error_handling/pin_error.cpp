/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** pin_error
*/

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "../exception/NonExistingPin.hpp"
#include "../exception/TooManyElementLink.hpp"
#include "../exception/LinkWrongFormat.hpp"
#include "../exception/UndeclaredChipset.hpp"
#include "../parser/parser.hpp"
#include "error_handling.hpp"

void non_existing_pin(std::vector<std::string> chipset_arr, std::vector<std::string> link_arr)
{
    std::vector<std::string> link_line;
    std::vector<std::string> comp1;
    std::vector<std::string> comp2;
    std::vector<std::string> chipset;
    size_t j = 0;

    for (const auto & i : link_arr) {
        link_line = split(i, ' ');
        if (link_line.size() != 2)
            throw(TooManyElementLink(i, link_line.size()));
        comp1 = split(link_line[0], ':');
        if (comp1.size() != 2)
            throw(LinkWrongFormat(i));
        comp2 = split(link_line[1], ':');
        if (comp2.size() != 2)
            throw(LinkWrongFormat(i));
        for (j = 0; j < chipset_arr.size(); j++) {
            chipset = split(chipset_arr[j], ' ');
            if (chipset[1] == comp1[0])
                break;
        }
        if (j == chipset_arr.size())
            throw(UndeclaredChipset(comp1[0]));
        auto it = EXISTING_PIN.find(chipset[0]);
        if (std::find(it->second.begin(), it->second.end(), atoi(comp1[1].c_str())) == it->second.end())
            throw(NonExistingPin(comp1[1], i));
    }
}