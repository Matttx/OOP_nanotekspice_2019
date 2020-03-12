    /*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Gate.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_GATE_HPP
#define OOP_NANOTEKSPICE_2019_GATE_HPP

#include <vector>
#include <map>
#include "IComponent.hpp"

namespace nts {
    class Gate {
    public:
        Gate(std::vector<size_t> input, std::vector<size_t> output, std::string type);
        std::string getType();
        std::map<size_t, Tristate> getInput() const;
        Tristate getInput(size_t pin) const;
        std::map<size_t, Tristate> getOutput() const;
        Tristate getOutput(size_t pin) const;
        virtual Tristate gate_operator(const std::map<size_t, Tristate>& _input) = 0;
        void setInput(size_t pin, Tristate value);
        void setOutput(size_t pin, Tristate value);
    private:
        std::map<size_t, Tristate> _input;
        std::map<size_t, Tristate> _output;
        std::string _type;
    };
}

#endif // OOP_NANOTEKSPICE_2019_GATE_HPP
