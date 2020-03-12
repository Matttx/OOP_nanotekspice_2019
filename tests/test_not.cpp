/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_not.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/gate/Not.hpp"

Test(gate_operator, test_not_true)
{
    nts::Not salut({1}, {2});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::FALSE));
    cr_assert_eq(salut.gate_operator(_input), nts::TRUE);
}

Test(gate_operator, test_not_false)
{
    nts::Not salut({1}, {2});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::TRUE));
    cr_assert_eq(salut.gate_operator(_input), nts::FALSE);
}

Test(gate_operator, test_not_undefined)
{
    nts::Not salut({1}, {2});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::UNDEFINED));
    cr_assert_eq(salut.gate_operator(_input), nts::UNDEFINED);
}
