#include "ScavTrap.hpp"
# include <iostream>

int main()
{
    std::cout << "Create ScavTrap :" << std::endl;
    ScavTrap scav("Guardian");
    std::cout << std::endl;

    std::cout << "Test ScavTrap :" << std::endl;
    scav.attack("Enemy1");
    scav.takeDamage(30);
    scav.beRepaired(20);
    scav.guardGate();
    std::cout << std::endl;

    std::cout << "Test multiple attacks :" << std::endl;
    scav.attack("Enemy2");
    scav.attack("Enemy3");
    std::cout << std::endl;

    std::cout << "Test copy constructor :" << std::endl;
    ScavTrap scav2(scav);
    scav2.attack("Enemy4");
    std::cout << std::endl;

    std::cout << "Test assignment operator :" << std::endl;
    ScavTrap scav3("Defender");
    scav3 = scav;
    scav3.guardGate();
    std::cout << std::endl;

    std::cout << "Create ClapTrap :" << std::endl;
    ClapTrap clap("BasicBot");
    clap.attack("Target");
    std::cout << std::endl;

    std::cout << "Test energy :" << std::endl;
    ScavTrap scav4("Tired");
    for (int i = 0; i < 51; i++) {
        scav4.attack("DummyTarget");
    }
    std::cout << std::endl;

    std::cout << "Destroy objects :" << std::endl;
    return 0;
}