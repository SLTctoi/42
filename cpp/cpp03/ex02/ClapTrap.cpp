# include "ClapTrap.hpp"
# include <iostream>


ClapTrap::ClapTrap() : _Hp(10), _Ep(10), _Ad(0) {
    std::cout << "ClapTrap " << this->_Name << " default is constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hp(10), _Ep(10), _Ad(0) {
    std::cout << "ClapTrap " << this->_Name << " is constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : _Name(copy._Name), _Hp(copy._Hp), _Ep(copy._Ep), _Ad(copy._Ad) {
    std::cout << "ClapTrap " << this->_Name << " is copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &op)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &op)
    {
        this->_Name = op._Name;
        this->_Hp = op._Hp;
        this->_Ep = op._Ep;
        this->_Ad = op._Ad;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->_Name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_Hp <= 0) {
        std::cout << "ClapTrap " << this->_Name << " can't attack because he is dead" << std::endl;
    } else if (this->_Ep <= 0) {
        std::cout << "ClapTrap " << this->_Name << " can't attack because he has no energy points" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_Name << " attacks " << target << ", causing " << this->_Ad << " points of damage!" << std::endl;
        this->_Ep--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_Hp <= 0){
        std::cout << "ClapTrap " << this->_Name << " can't take damage because he is dead" << std::endl;
    } else if (this->_Hp > (int)amount) {
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
        std::cout << "ClapTrap " << this->_Name << " regains " << amount << " hit points; he has " << this->_Hp << " hit points left" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_Name << " can't regains hit points because he has no energy points" << std::endl;
    }
}