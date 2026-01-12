#include "ScavTrap.hpp"
# include <iostream>

int main()
{
    std::cout << "Create ScavTrap :" << std::endl;
    ScavTrap scav("Guardian");
    std::cout << std::endl;

    std::cout << "Test :" << std::endl;
    scav.attack("Enemy");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "Destroy ScavTrap :" << std::endl;
    return 0;
}