/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** parser.cpp
*/

#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include "parser.hpp"
#include "../exception/UnknownFile.hpp"
#include "../exception/NoFilePart.hpp"

void Parser::setChipset(std::vector<std::string> arr_clean) {
    size_t i = 1;

    if (arr_clean[0] != ".chipsets:")
        throw NoFilePart(".chipsets");
    for (; i < arr_clean.size() && arr_clean[i] != ".links:"; i++)
        _chipset_arr.push_back(arr_clean[i]);
    if (i == arr_clean.size() - 1)
        throw NoFilePart(".links");
}

void Parser::setLink(std::vector<std::string> arr_clean, size_t idx_start) {
    if (idx_start >= arr_clean.size() || arr_clean[idx_start] != ".links:") {
        throw NoFilePart(".links");
    }
    for (++idx_start; idx_start < arr_clean.size(); idx_start++) {
        _link_arr.push_back(arr_clean[idx_start]);
    }
}

Parser::Parser(const std::string& filename)
{
    _file = filename;
    try {
        setFile(filename);
    } catch (const UnknownFile &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    try {
        setChipset(_arr_clean);
        setLink(_arr_clean, _chipset_arr.size() + 1);
    } catch (const NoFilePart &e) {
        std::cerr << e.what() << std::endl;
        exit(84);
    }
    error_handling(_chipset_arr, _link_arr);
}

std::vector<std::string> split(const std::string& str, char delimiter)
{
    std::vector<std::string> str_vec;
    std::string new_str;

    for (char i : str) {
        if (i != delimiter)
            new_str += i;
        else {
            str_vec.push_back(new_str);
            new_str.clear();
        }
    }
    str_vec.push_back(new_str);
    return str_vec;
}

std::string &ltrim(std::string &str, const std::string& chars = SPACES)
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}

std::string& rtrim(std::string& str, const std::string& chars = SPACES)
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}

std::string& Parser::trim(std::string& str, const std::string& chars)
{
    return ltrim(rtrim(str, chars), chars);
}

template<typename T, typename P>
T Parser::remove_space(T beg, T end, P pred)
{
    T dest = beg;
    bool state = false;

    for (T itr = beg; itr != end; ++itr)
        if (!pred(*itr)) {
            *(dest++) = *itr;
            state = false;
        }
        else {
            if (pred(*dest - 1) || !state) {
                *(dest++) = ' ';
                state = true;
            }
        }
    return dest;
}

void Parser::setFile(const std::string& filename)
{
    std::ifstream file;
    std::string line;
    std::vector<std::string> arr_line;

    file.open(filename);
    if (!file.is_open()) {
        throw UnknownFile(filename);
    }
    while (getline(file, line))
        arr_line.push_back(trim(line));
    for (auto & i : arr_line)
        i.erase(remove_space(i.begin(), i.end(), isspace), i.end());
    for (auto & i : arr_line)
        i.erase(std::find(i.begin(), i.end(), '#'), i.end());
    for (auto & i : arr_line)
        if (!i.empty())
            _arr_clean.push_back(i);
}

const std::vector<std::string> &Parser::getArrClean() const {
    return _arr_clean;
}

const std::vector<std::string> &Parser::getChipsetArr() const {
    return _chipset_arr;
}

const std::vector<std::string> &Parser::getLinkArr() const {
    return _link_arr;
}

const std::string &Parser::getFile() const {
    return _file;
}
