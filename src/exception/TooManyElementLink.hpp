/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** TooManyElementLink
*/

#ifndef TOOMANYELEMENTLINK_HPP_
#define TOOMANYELEMENTLINK_HPP_

#include <string>
#include <exception>

class TooManyElementLink : public std::exception{
    public:
        TooManyElementLink(const std::string &what, size_t size);
        const char *what() const noexcept override;

    protected:
    private:
        std::string _what;
};

#endif /* !TOOMANYELEMENTLINK_HPP_ */
