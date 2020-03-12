/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** promp.cpp
*/

#include <iostream>
#include "component/c_input.hpp"
#include "circuit/Circuit.hpp"
#include "exception/UnknownFile.hpp"
#include "parser/parser.hpp"
#include "exception/InputNoValue.hpp"
#include "exception/NotLinkedOutput.hpp"
#include "exception/NoOutput.hpp"
#include "error_handling/error_handling.hpp"

std::string get_command() {
    std::string command;

    std::cout << "> ";
    std::getline(std::cin, command);
    if (std::cin.eof())
        exit(0);
    return command;
}

void prompt(Circuit& circuit) {
    std::string command;
    bool func = false;

    try {
        verif_input_val(circuit);
        linked_output(circuit);
    } catch (const InputNoValue &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch(const NotLinkedOutput &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch(const NoOutput &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    circuit.simulate();
    circuit.display();
    while (1) {
        command = get_command();
        for (int i = 0; EXEC[i].name != ""; i++) {
            if (EXEC[i].name == command) {
                (circuit.*EXEC[i].ptr)();
                func = true;
            }
        }
        if (!func) {
            auto vec = split(command, '=');
            if (vec.size() == 2)
                circuit.setValue(vec);
        }
        func = false;
    }
}