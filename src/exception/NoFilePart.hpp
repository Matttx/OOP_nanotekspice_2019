/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoFilePart
*/

#ifndef NOFILEPART_HPP_
#define NOFILEPART_HPP_

#include <string>
#include <exception>

class NoFilePart : public std::exception{
    public:
        NoFilePart(const std::string &name);
        const char *what() const noexcept override;
    protected:
    private:
        std::string _what;
};

#endif /* !NOFILEPART_HPP_ */
