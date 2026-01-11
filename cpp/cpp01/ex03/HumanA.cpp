#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string &name, Weapon &weapon) : _Name(name), _Weapon(weapon) {}

HumanA::~HumanA() {
    std::cout << _Name << " is destroyed" << std::endl;
}

void HumanA::attack() const {
    std::cout << _Name << " attacks with their " << _Weapon.getType() << std::endl;
}