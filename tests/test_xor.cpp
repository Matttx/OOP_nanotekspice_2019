/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_xor.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/gate/Xor.hpp"

Test(gate_operator, test_xor_true_1)
{
    nts::Xor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::TRUE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::FALSE));
    cr_assert_eq(salut.gate_operator(_input), nts::TRUE);
}

Test(gate_operator, test_xor_true_2)
{
    nts::Xor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::FALSE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::TRUE));
    cr_assert_eq(salut.gate_operator(_input), nts::TRUE);
}

Test(gate_operator, test_xor_false_1)
{
    nts::Xor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::FALSE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::FALSE));
    cr_assert_eq(salut.gate_operator(_input), nts::FALSE);
}

Test(gate_operator, test_xor_false_2)
{
    nts::Xor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::TRUE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::TRUE));
    cr_assert_eq(salut.gate_operator(_input), nts::FALSE);
}

Test(gate_operator, test_xor_undefined_1)
{
    nts::Xor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::UNDEFINED));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::UNDEFINED));
    cr_assert_eq(salut.gate_operator(_input), nts::UNDEFINED);
}

Test(gate_operator, test_xor_undefined_2)
{
    nts::Xor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::TRUE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::UNDEFINED));
    cr_assert_eq(salut.gate_operator(_input), nts::UNDEFINED);
}