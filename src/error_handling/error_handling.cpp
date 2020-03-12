/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** error_handling
*/

#include <iostream>
#include <utility>
#include "error_handling.hpp"
#include "../exception/InvalidChipset.hpp"
#include "../exception/SameChipsetName.hpp"
#include "../exception/NonExistingPin.hpp"
#include "../exception/TooManyElementLink.hpp"
#include "../exception/LinkWrongFormat.hpp"
#include "../exception/UndeclaredChipset.hpp"

void error_handling(const std::vector<std::string>& chipset_arr, std::vector<std::string> link_arr) {
    try {
        check_chipset(chipset_arr);
        check_same_chipset(chipset_arr);    
        } catch (const InvalidChipset &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        } catch (const SameChipsetName &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    try {
        non_existing_pin(chipset_arr, std::move(link_arr));
    } catch (const TooManyElementLink &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch (const LinkWrongFormat &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch (const UndeclaredChipset &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    } catch (const NonExistingPin &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
}