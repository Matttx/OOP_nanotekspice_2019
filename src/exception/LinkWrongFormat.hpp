/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** LinkWrongFormat
*/

#ifndef LINKWRONGFORMAT_HPP_
#define LINKWRONGFORMAT_HPP_


#include <string>
#include <exception>

class LinkWrongFormat : public std::exception{
    public:
        LinkWrongFormat(const std::string &name);
        const char *what() const noexcept override;
    protected:
    private:
        std::string _what;
};

#endif /* !LINKWRONGFORMAT_HPP_ */
