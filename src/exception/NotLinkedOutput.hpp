/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NotLinkedOutput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NOTLINKEDOUTPUT_HPP
#define OOP_NANOTEKSPICE_2019_NOTLINKEDOUTPUT_HPP


#include <string>
#include <exception>

class NotLinkedOutput : public std::exception{
public:
    NotLinkedOutput(const std::string &name);
    const char *what() const noexcept override;
protected:
private:
    std::string _what;
};


#endif // OOP_NANOTEKSPICE_2019_NOTLINKEDOUTPUT_HPP
