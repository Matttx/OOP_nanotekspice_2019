/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** parser.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_PARSER_HPP
#define OOP_NANOTEKSPICE_2019_PARSER_HPP

#include "../circuit/Circuit.hpp"

#define SPACES "\t\n\v\f\r "

class Parser {
public:
    explicit Parser(const std::string& filename);
    std::string& trim(std::string& str, const std::string& chars = SPACES);
    template<typename T, typename P>
    T remove_space(T beg, T end, P pred);
    void setFile(const std::string& filename);
    void setChipset(std::vector<std::string> arr_clean);
    void setLink(std::vector<std::string> arr_clean, size_t idx_start);
    const std::string &getFile() const;
    const std::vector<std::string> &getArrClean() const;
    const std::vector<std::string> &getChipsetArr() const;
    const std::vector<std::string> &getLinkArr() const;

private:
    std::string _file;
    std::vector<std::string> _arr_clean;
    std::vector<std::string> _chipset_arr;
    std::vector<std::string> _link_arr;


};
std::vector<std::string> split(const std::string& str, char delimiter);
void error_handling(const std::vector<std::string>& chipset_arr, std::vector<std::string> link_arr);
#endif // OOP_NANOTEKSPICE_2019_PARSER_HPP
