#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: ShrubberyCreationForm - Success ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        ShrubberyCreationForm shrub("home");
        
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: ShrubberyCreationForm - Not signed ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm shrub2("garden");
        
        std::cout << alice << std::endl;
        std::cout << shrub2 << std::endl;
        
        alice.executeForm(shrub2);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: RobotomyRequestForm - Success ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << charlie << std::endl;
        std::cout << robot << std::endl;
        
        charlie.signForm(robot);
        charlie.executeForm(robot);
        charlie.executeForm(robot);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: RobotomyRequestForm - Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 70);
        Bureaucrat eve("Eve", 50);
        RobotomyRequestForm robot2("Marvin");
        
        std::cout << dave << std::endl;
        std::cout << eve << std::endl;
        std::cout << robot2 << std::endl;
        
        dave.signForm(robot2);
        eve.executeForm(robot2);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: PresidentialPardonForm - Success ===" << std::endl;
    try {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: PresidentialPardonForm - Grade too low ===" << std::endl;
    try {
        Bureaucrat frank("Frank", 10);
        PresidentialPardonForm pardon2("Ford Prefect");
        
        std::cout << frank << std::endl;
        std::cout << pardon2 << std::endl;
        
        frank.signForm(pardon2);
        frank.executeForm(pardon2);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: All three forms with proper bureaucrats ===" << std::endl;
    try {
        Bureaucrat junior("Junior", 140);
        Bureaucrat senior("Senior", 40);
        Bureaucrat ceo("CEO", 1);
        
        ShrubberyCreationForm shrub("office");
        RobotomyRequestForm robot("Intern");
        PresidentialPardonForm pardon("Boss");
        
        junior.signForm(shrub);
        junior.executeForm(shrub);
        
        senior.signForm(robot);
        senior.executeForm(robot);
        
        ceo.signForm(pardon);
        ceo.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Grade too low to sign ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        PresidentialPardonForm pardon3("Zaphod");
        
        std::cout << intern << std::endl;
        std::cout << pardon3 << std::endl;
        
        intern.signForm(pardon3);
        intern.executeForm(pardon3);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Difference between sign and execute grades ===" << std::endl;
    try {
        Bureaucrat signer("Signer", 20);
        Bureaucrat executor("Executor", 3);
        PresidentialPardonForm pardon4("Test Subject");
        
        std::cout << signer << std::endl;
        std::cout << executor << std::endl;
        std::cout << pardon4 << std::endl;
        
        signer.signForm(pardon4);
        std::cout << "After signing: " << pardon4 << std::endl;
        
        signer.executeForm(pardon4);
        std::cout << std::endl;
        
        executor.executeForm(pardon4);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 10: Exact grade boundaries ===" << std::endl;
    try {
        Bureaucrat exact1("Exact145", 145);
        Bureaucrat exact2("Exact137", 137);
        ShrubberyCreationForm shrub2("boundary_test");
        
        std::cout << exact1 << std::endl;
        std::cout << exact2 << std::endl;
        std::cout << shrub2 << std::endl;
        
        exact1.signForm(shrub2);
        
        exact2.executeForm(shrub2);
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
