/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** chipset_name
*/

#include "../exception/InvalidChipset.hpp"
#include "../exception/SameChipsetName.hpp"
#include "../parser/parser.hpp"

void check_chipset(std::vector<std::string> chipset_arr) {
    std::vector<std::string> valid_chipset = {"4001", "4008", "4011", "4013", "4017", "4030", "4040", "4069", "4071", "4081", "4094", "4514", "4801", "2716", "input", "clock", "true", "false", "output"};
    size_t j = 0;
    std::vector<std::string> tmp;

    for (const auto & i : chipset_arr) {
        tmp = split(i, ' ');
        for (j = 0; j < valid_chipset.size(); j++)
            if (tmp[0] == valid_chipset[j])
                break;
        if (j == valid_chipset.size())
            throw InvalidChipset(tmp[0]);
    }
}

void check_same_chipset(std::vector<std::string> chipset_arr)
{
    std::vector<std::string> act_chipset;
    std::vector<std::string> comp_chipset;

    for (size_t i = 0; i < chipset_arr.size(); i++) {
        act_chipset = split(chipset_arr[i], ' ');
        for (size_t j = 0; j < chipset_arr.size(); j++) {
            comp_chipset = split(chipset_arr[j], ' ');
            if (act_chipset[1] == comp_chipset[1] && i != j)
                throw SameChipsetName(act_chipset[1]);
        }
    }
}