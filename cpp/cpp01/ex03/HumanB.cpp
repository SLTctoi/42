#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string &name) : _Name(name), _Weapon(NULL) {}

HumanB::~HumanB() {
    std::cout << _Name << " is destroyed" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
    _Weapon = &weapon;
}

void HumanB::attack() const {
    if (_Weapon)
        std::cout << _Name << " attacks with their " << _Weapon->getType() << std::endl;
    else
        std::cout << _Name << " has no weapon" << std::endl;
}
