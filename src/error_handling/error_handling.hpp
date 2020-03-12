/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** error_handling
*/

#ifndef ERROR_HANDLING_HPP_
#define ERROR_HANDLING_HPP_

#include <vector>
#include <string>
#include <map>
#include "../circuit/Circuit.hpp"

void check_chipset(std::vector<std::string> chipset_arr);
void check_same_chipset(std::vector<std::string> chipset_arr);
void non_existing_pin(std::vector<std::string> chipset_arr, std::vector<std::string> link_arr);
void verif_input_val(Circuit &circuit);
void linked_output(Circuit &circuit);

using pin_map_t = const std::map<std::string, std::vector<size_t>>;
pin_map_t EXISTING_PIN = {
    {"4001", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}},
    {"4008", {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}},
    {"4011", {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13}},
    {"4013", {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13}},
    {"4017", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}},
    {"4030", {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13}},
    {"4040", {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}},
    {"4069", {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13}},
    {"4071", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13}},
    {"4081", {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13}},
    {"4094", {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}},
    {"4503", {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}},
    {"4512", {1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15}},
    {"4514", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}},
    {"4801", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}},
    {"2716", {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23}},
    {"clock", {1}},
    {"false", {1}},
    {"input", {1}},
    {"output", {1}},
    {"true", {1}}

};
#endif /* !ERROR_HANDLING_HPP_ */
