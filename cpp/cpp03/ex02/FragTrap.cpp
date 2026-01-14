# include "FragTrap.hpp"
# include <iostream>

FragTrap::FragTrap() : ClapTrap() {
    _Hp = 100;
    _Ep = 100;
    _Ad = 30;
    std::cout << "FragTrap " << _Name << " default is constructed!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _Hp = 100;
    _Ep = 100;
    _Ad = 30;
    std::cout << "FragTrap " << _Name << " is constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "FragTrap " << _Name << " is copied!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &op)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &op)
    {
        ClapTrap::operator=(op);
    }
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << _Name << " is destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _Name << " requests a positive high five!" << std::endl;
}