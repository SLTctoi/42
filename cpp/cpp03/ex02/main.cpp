# include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "Create FragTrap :" << std::endl;
    FragTrap frag("Bomber");
    std::cout << std::endl;

    std::cout << "Test FragTrap :" << std::endl;
    frag.attack("Target1");
    frag.takeDamage(40);
    frag.beRepaired(25);
    frag.highFivesGuys();
    std::cout << std::endl;

    std::cout << "Test copy constructor :" << std::endl;
    FragTrap frag2(frag);
    frag2.attack("Target2");
    frag2.highFivesGuys();
    std::cout << std::endl;

    std::cout << "Test assignment operator :" << std::endl;
    FragTrap frag3("Destroyer");
    frag3 = frag;
    frag3.highFivesGuys();
    std::cout << std::endl;

    std::cout << "Create ScavTrap :" << std::endl;
    ScavTrap scav("Guardian");
    scav.attack("Target3");
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "Test ScavTrap copy :" << std::endl;
    ScavTrap scav2(scav);
    scav2.guardGate();
    std::cout << std::endl;

    std::cout << "Create ClapTrap :" << std::endl;
    ClapTrap clap("BasicBot");
    clap.attack("Target4");
    std::cout << std::endl;

    std::cout << "Test energy :" << std::endl;
    FragTrap frag4("Tired");
    for (int i = 0; i < 101; i++) {
        frag4.attack("Dummy");
    }
    frag4.beRepaired(10);
    std::cout << std::endl;

    std::cout << "Test death :" << std::endl;
    FragTrap frag5("Doomed");
    frag5.takeDamage(150);
    frag5.attack("Target5");
    frag5.beRepaired(20);
    std::cout << std::endl;

    std::cout << "Destroy all :" << std::endl;
    return 0;
}