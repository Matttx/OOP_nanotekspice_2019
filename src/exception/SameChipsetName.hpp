/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** SameChipsetName
*/

#ifndef SAMECHIPSETNAME_HPP_
#define SAMECHIPSETNAME_HPP_

#include <string>
#include <exception>

class SameChipsetName : public std::exception{
    public:
        SameChipsetName(const std::string &pin_number);
        const char *what() const noexcept override;

    protected:
    private:
        std::string _what;
};

#endif /* !SAMECHIPSETNAME_HPP_ */
