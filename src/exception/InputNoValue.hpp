/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** InputNoValue
*/

#ifndef INPUTNOVALUE_HPP_
#define INPUTNOVALUE_HPP_

#include <string>
#include <exception>

class InputNoValue : std::exception {
    public:
        InputNoValue(const std::string &name);
        const char *what() const noexcept override;
    protected:
    private:
        std::string _what;
};

#endif /* !INPUTNOVALUE_HPP_ */
