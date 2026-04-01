#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Intern creates robotomy request ===" << std::endl;
    try {
        Intern someRandomIntern;
        AForm* rrf;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        
        if (rrf) {
            Bureaucrat bob("Bob", 1);
            std::cout << *rrf << std::endl;
            bob.signForm(*rrf);
            bob.executeForm(*rrf);
            delete rrf;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Intern creates shrubbery creation ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("shrubbery creation", "garden");
        
        if (form) {
            Bureaucrat alice("Alice", 100);
            std::cout << *form << std::endl;
            alice.signForm(*form);
            alice.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Intern creates presidential pardon ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("presidential pardon", "Arthur Dent");
        
        if (form) {
            Bureaucrat president("President", 1);
            std::cout << *form << std::endl;
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Intern with invalid form name ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        form = intern.makeForm("invalid form", "target");
        
        if (form) {
            std::cout << *form << std::endl;
            delete form;
        } else {
            std::cout << "Form was not created (NULL returned)" << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Multiple forms created by intern ===" << std::endl;
    try {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* forms[3];
        
        forms[0] = intern.makeForm("shrubbery creation", "home");
        forms[1] = intern.makeForm("robotomy request", "Employee");
        forms[2] = intern.makeForm("presidential pardon", "Criminal");
        
        for (int i = 0; i < 3; i++) {
            if (forms[i]) {
                std::cout << *forms[i] << std::endl;
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
                delete forms[i];
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Testing all invalid form names ===" << std::endl;
    try {
        Intern intern;
        AForm* form;
        
        std::string invalidNames[] = {
            "unknown form",
            "bureaucrat form",
            "robotomy",
            "shrubbery",
            "presidential",
            ""
        };
        
        for (int i = 0; i < 6; i++) {
            form = intern.makeForm(invalidNames[i], "target");
            if (!form) {
                std::cout << "-> Correctly returned NULL for invalid name" << std::endl;
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Memory leak test - create and delete ===" << std::endl;
    try {
        Intern intern;
        
        for (int i = 0; i < 3; i++) {
            AForm* form = intern.makeForm("robotomy request", "TestTarget");
            if (form) {
                std::cout << "Form " << i + 1 << " created and deleted" << std::endl;
                delete form;
            }
        }
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
