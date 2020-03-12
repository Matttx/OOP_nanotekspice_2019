/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** UndeclaredChipset
*/

#ifndef UNDECLAREDCHIPSET_HPP_
#define UNDECLAREDCHIPSET_HPP_

#include <string>
#include <exception>

class UndeclaredChipset : public std::exception{
    public:
        UndeclaredChipset(const std::string &pin_number);
        const char *what() const noexcept override;

    protected:
    private:
        std::string _what;
};

#endif /* !UNDECLAREDCHIPSET_HPP_ */
