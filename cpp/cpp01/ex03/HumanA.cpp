#include "HumanA.hpp"

HumanA::HumanA(std::string name, std::string weapon) {
    _Name = name;
    _Weapon = weapon;
}

HumanA::~HumanA(){
    std::cout << _Name << " is destroyed" << std::endl;
}

void HumanA::attack() {
    std::cout << _Name << " attacks with their " << _Weapon << std::endl; 
}

std::string const HumanA::getName() {
    return this->_Name;
}

std::string const HumanA::getWeapon() {
    return this->_Weapon;
}