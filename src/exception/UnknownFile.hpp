/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** UnknownFile
*/

#ifndef UNKNOWNFILE_HPP_
#define UNKNOWNFILE_HPP_

#include <string>
#include <exception>

class UnknownFile : public std::exception{
    public:
        UnknownFile(const std::string &what);
        const char *what() const noexcept override;

    protected:
    private:
        std::string _what;
};

#endif /* !UNKNOWNFILE_HPP_ */
