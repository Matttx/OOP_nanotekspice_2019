/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit.hpp
*/

#ifndef OOP_NANOTEKSPICE_2019_Circuit_HPP
#define OOP_NANOTEKSPICE_2019_Circuit_HPP

#include <vector>
#include <memory>
#include "../component/Component.hpp"
#include "../component/c_2716.hpp"
#include "../component/c_4001.hpp"
#include "../component/c_4008.hpp"
#include "../component/c_4011.hpp"
#include "../component/c_4013.hpp"
#include "../component/c_4017.hpp"
#include "../component/c_4030.hpp"
#include "../component/c_4040.hpp"
#include "../component/c_4069.hpp"
#include "../component/c_4071.hpp"
#include "../component/c_4081.hpp"
#include "../component/c_4094.hpp"
#include "../component/c_4514.hpp"
#include "../component/c_4801.hpp"
#include "../component/c_clock.hpp"
#include "../component/c_false.hpp"
#include "../component/c_input.hpp"
#include "../component/c_output.hpp"
#include "../component/c_true.hpp"

class Circuit {
public:
    Circuit(const std::vector<std::string>& chipset, const std::vector<std::string>& link, char **argv);
    Circuit(const Circuit &circuit);
    ~Circuit() = default;
    Circuit &operator=(const Circuit &circuit);
    void dump();
    void exit();
    void loop();
    void simulate();
    void display();
    void manage_clock();
    nts::IComponent *getComp(size_t pos) const;
    nts::IComponent *getComp(const std::string &name) const;
    std::vector<nts::IComponent *> getComp() const;
    void setComponent(std::unique_ptr<nts::IComponent> comp);
    void setValue(std::vector<std::string> vec);
private:
    std::vector<std::unique_ptr<nts::IComponent>> _comp;
};

using map_t = const std::map <std::string, std::function<std::unique_ptr<nts::IComponent>(std::string)>>;
map_t COMPONENT_CONSTRUCTOR = {
        {"4001", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4001(value)); return p1;}},
        {"4008", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4008(value)); return p1;}},
        {"4011", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4011(value)); return p1;}},
        {"4013", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4013(value)); return p1;}},
        {"4017", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4017(value)); return p1;}},
        {"4030", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4030(value)); return p1;}},
        {"4040", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4040(value)); return p1;}},
        {"4069", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4069(value)); return p1;}},
        {"4071", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4071(value)); return p1;}},
        {"4081", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4081(value)); return p1;}},
        {"4094", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4094(value)); return p1;}},
        {"4514", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4514(value)); return p1;}},
        {"4801", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_4801(value)); return p1;}},
        {"2716", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_2716(value)); return p1;}},
        {"clock", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_clock(value)); return p1;}},
        {"false", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_false(value)); return p1;}},
        {"input", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_input(value)); return p1;}},
        {"output", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_output(value)); return p1;}},
        {"true", [](const std::string& value) -> std::unique_ptr<nts::IComponent> {std::unique_ptr<nts::IComponent> p1(new nts::c_true(value)); return p1;}}
};

typedef struct execution_s {
    std::string name;
    void (Circuit:: *ptr)();
} execution_t;

static const execution_t EXEC[] = {
        {"dump", &Circuit::dump},
        {"exit", &Circuit::exit},
        {"display", &Circuit::display},
        {"simulate", &Circuit::simulate},
        {"loop", &Circuit::loop},
        {"", nullptr}
};

#endif // OOP_NANOTEKSPICE_2019_Circuit_HPP
