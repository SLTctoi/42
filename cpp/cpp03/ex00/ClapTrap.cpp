# include "ClapTrap.hpp"
# include <iostream>


ClapTrap::ClapTrap(std::string name) : _Name(name), _Hp(10), _Ep(10), _Ad(0) {}

ClapTrap::~ClapTrap() {}

void ClapTrap::attack(const std::string& target) {
    if (this->_Ep > 0 && this->_Hp > 0)
    {
        std::cout << "ClapTrap " << this->_Name << " attacks " << target << " , causing " << this->_Ad << " Points of damage!" << std::endl;
        this->_Ep--;
    } else if (this->_Ep <= 0) {
        std::cout << "ClapTrap " << this->_Name << " can't attack because he has no energy points" << std::endl;
    } else if (this->_Ad <= 0) {
        std::cout << "ClapTrap " << this->_Name << " can't attack because he has no attack damage" << std::endl;
    } else if (this->_Hp <= 0) {
        std::cout << "ClapTrap " << this->_Name << " can't attack because he is dead" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_Hp <= 0){
        std::cout << "ClapTrap " << this->_Name << " can't take damage because he is dead" << std::endl;
    } else if (this->_Hp > amount) {
        this->_Hp -= amount;
        std::cout << "ClapTrap " << this->_Name << " lost " << amount << " hit points; he has " << this->_Hp << " hit points left" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_Name << " lost " << this->_Hp << " hit points and dies" << std::endl;
        this->_Hp = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_Hp <= 0){
        std::cout << "ClapTrap " << this->_Name << " can't be repaired because he is dead" << std::endl;
    } else if (this->_Ep > 0) {
        this->_Hp += amount;
        this->_Ep--;
        std::cout << "ClapTrap " << this->_Name << " regains " << amount << " hit points"<< std::endl;
    } else {
        std::cout << "ClapTrap " << this->_Name << " can't regains hit points because he has no energy points" << std::endl;
    }
}