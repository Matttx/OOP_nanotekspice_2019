/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** NoOutput.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_NOOUTPUT_HPP
#define OOP_NANOTEKSPICE_2019_NOOUTPUT_HPP


#include <string>
#include <exception>

class NoOutput : public std::exception{
public:
    NoOutput();
    const char *what() const noexcept override;
protected:
private:
    std::string _what;
};

#endif // OOP_NANOTEKSPICE_2019_NOOUTPUT_HPP
