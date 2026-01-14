# include "ClapTrap.hpp"
# include <iostream>

int main(void)
{
    std::cout << "Basic attacks :"<< std::endl;
    ClapTrap clap1("Bob");
    clap1.attack("target1");
    clap1.attack("target2");
    std::cout << std::endl;

    std::cout << "Taking damage and die :"<< std::endl;
    ClapTrap clap2("bab");
    clap2.takeDamage(3);
    clap2.takeDamage(5);
    clap2.takeDamage(10);
    clap2.attack("target3");
    std::cout << std::endl;

    std::cout << "Repairing :"<< std::endl;
    ClapTrap clap3("bib");
    clap3.takeDamage(7);
    clap3.beRepaired(5);
    std::cout << std::endl;

    std::cout << "No energy :"<< std::endl;
    ClapTrap clap4("byb");
    for (int i = 0; i < 11; i++) {
        clap4.attack("target4");
    }
    clap4.beRepaired(2);
    std::cout << std::endl;

    std::cout << "All action :"<< std::endl;
    ClapTrap clap5("bub");
    clap5.attack("target5");
    clap5.takeDamage(4);
    clap5.beRepaired(3);
    clap5.attack("target5");
    clap5.beRepaired(2);
    std::cout << std::endl;

    std::cout << "Copy constructor :"<< std::endl;
    ClapTrap clap6("Original");
    ClapTrap clap7(clap6);
    clap7.attack("target6");
    std::cout << std::endl;

    std::cout << "Destructors :"<< std::endl;
    return 0;
}