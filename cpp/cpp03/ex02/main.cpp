# include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Create FragTrap :" << std::endl;
    FragTrap frag("bob");
    std::cout << std::endl;
    std::cout << "Test FragTrap :" << std::endl;
    frag.attack("Target");
    frag.takeDamage(40);
    frag.beRepaired(25);
    frag.highFivesGuys();
    std::cout << std::endl;
    std::cout << "Create ScavTrap :" << std::endl;
    ScavTrap scav("bib");
    scav.guardGate();
    std::cout << std::endl;
    std::cout << "Destroy all :" << std::endl;
    return 0;
}