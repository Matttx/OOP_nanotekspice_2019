/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InvalidChipset
*/

#ifndef INVALIDCHIPSET_HPP_
#define INVALIDCHIPSET_HPP_

#include <string>
#include <vector>
#include <exception>

void check_chipset(std::vector<std::string> chipset_arr);

class InvalidChipset : public std::exception{
    public:
        InvalidChipset(const std::string &name);
        const char *what() const noexcept override;

    protected:
    private:
        std::string _what;
};

#endif /* !INVALIDCHIPSET_HPP_ */
