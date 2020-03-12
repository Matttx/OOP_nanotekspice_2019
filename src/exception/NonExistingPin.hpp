/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NonExistingPin
*/

#ifndef NONEXISTINGPIN_HPP_
#define NONEXISTINGPIN_HPP_

#include <string>
#include <exception>

class NonExistingPin : public std::exception{
    public:
        NonExistingPin(const std::string &what, const std::string &comp_name);
        const char *what() const noexcept override;

    protected:
    private:
        std::string _what;
};

#endif /* !NONEXISTINGPIN_HPP_ */
