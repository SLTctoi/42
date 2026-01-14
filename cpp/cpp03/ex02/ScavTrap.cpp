# include "ScavTrap.hpp"
# include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _Hp = 100;
    _Ep = 50;
    _Ad = 20;
    std::cout << "ScavTrap " << _Name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap() {
    _Hp = 100;
    _Ep = 50;
    _Ad = 20;
    std::cout << "ClapTrap " << this->_Name << " default is constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &op)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &op)
    {
        ClapTrap::operator=(op);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _Name << " is destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_Hp <= 0) {
        std::cout << "ScavTrap " << _Name << " can't attack because he is dead" << std::endl;
    } else if (_Ep <= 0) {
        std::cout << "ScavTrap " << _Name << " can't attack because he has no energy points" << std::endl;
    } else {
        std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing " << _Ad << " points of damage!" << std::endl;
        _Ep--;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode!" << std::endl;
}