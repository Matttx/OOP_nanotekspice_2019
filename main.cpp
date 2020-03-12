/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** main.cpp
*/

#include <iostream>
#include "src/circuit/Circuit.hpp"
#include "src/parser/parser.hpp"
#include "include/prompt.hpp"
#include "src/exception/UndeclaredChipset.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 84;
    Parser parser(argv[1]);
    try {
        Circuit circuit(parser.getChipsetArr(), parser.getLinkArr(), argv);
        prompt(circuit);
    } catch(UndeclaredChipset &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}