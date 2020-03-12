/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** test_nor.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../src/gate/Nor.hpp"

Test(gate_operator, test_nor_false_1) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::FALSE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::TRUE));
    cr_assert_eq(salut.gate_operator(_input), nts::FALSE);
}

Test(gate_operator, test_nor_false_2) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::TRUE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::FALSE));
    cr_assert_eq(salut.gate_operator(_input), nts::FALSE);
}

Test(gate_operator, test_nor_false_3) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::TRUE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::TRUE));
    cr_assert_eq(salut.gate_operator(_input), nts::FALSE);
}

Test(gate_operator, test_nor_undefined_1) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::UNDEFINED));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::FALSE));
    cr_assert_eq(salut.gate_operator(_input), nts::UNDEFINED);
}

Test(gate_operator, test_nor_undefined_2) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::FALSE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::UNDEFINED));
    cr_assert_eq(salut.gate_operator(_input), nts::UNDEFINED);
}

Test(gate_operator, test_nor_undefined_3) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::UNDEFINED));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::UNDEFINED));
    cr_assert_eq(salut.gate_operator(_input), nts::UNDEFINED);
}

Test(gate_operator, test_nor_true) {
    nts::Nor salut({1,2}, {3});
    std::map<size_t, nts::Tristate> _input;
    _input.insert(std::pair<size_t, nts::Tristate>(0, nts::FALSE));
    _input.insert(std::pair<size_t, nts::Tristate>(1, nts::FALSE));
    cr_assert_eq(salut.gate_operator(_input), nts::TRUE);
}