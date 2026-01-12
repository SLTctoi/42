# include "FragTrap.hpp"
# include <iostream>

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _Hp = 100;
    _Ep = 100;
    _Ad = 30;
    std::cout << "FragTrap " << _Name << " is constructed!" << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _Name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _Name << " requests a positive high five!" << std::endl;
}