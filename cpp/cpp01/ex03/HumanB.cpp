#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    _Name = name;
    _Weapon = NULL;
}

HumanB::~HumanB(){
    std::cout << _Name << " is destroyed" << std::endl;
}

void HumanB::attack() {
    std::cout << _Name << " attacks with their " << _Weapon << std::endl; 
}

std::string const HumanB::getName() {
    return _Name;
}

std::string const HumanB::getWeapon() {
    return _Weapon;
}

std::string HumanB::setWeapon( const std::string& weapon) {
    _Weapon = weapon;
}
