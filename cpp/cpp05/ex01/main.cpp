#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Creating valid forms ===" << std::endl;
    try {
        Form tax("Tax Form", 50, 25);
        std::cout << tax << std::endl;
        
        Form vip("VIP Form", 1, 1);
        std::cout << vip << std::endl;
        
        Form basic("Basic Form", 150, 150);
        std::cout << basic << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Form grade too high (0) ===" << std::endl;
    try {
        Form invalid("Invalid Form", 0, 50);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Form grade too low (151) ===" << std::endl;
    try {
        Form invalid("Invalid Form", 50, 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Bureaucrat signing a form (success) ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 30);
        Form contract("Contract", 50, 25);
        
        std::cout << alice << std::endl;
        std::cout << contract << std::endl;
        
        alice.signForm(contract);
        std::cout << contract << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Bureaucrat signing a form (failure - grade too low) ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form vipContract("VIP Contract", 50, 25);
        
        std::cout << bob << std::endl;
        std::cout << vipContract << std::endl;
        
        bob.signForm(vipContract);
        std::cout << vipContract << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Multiple signatures on same form ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 10);
        Bureaucrat dave("Dave", 5);
        Form important("Important Document", 20, 10);
        
        std::cout << important << std::endl;
        
        charlie.signForm(important);
        std::cout << important << std::endl;
        
        dave.signForm(important);
        std::cout << important << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Edge case - grade 1 bureaucrat ===" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        Form topSecret("Top Secret", 1, 1);
        
        std::cout << ceo << std::endl;
        std::cout << topSecret << std::endl;
        
        ceo.signForm(topSecret);
        std::cout << topSecret << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Edge case - grade 150 bureaucrat ===" << std::endl;
    try {
        Bureaucrat intern("Intern", 150);
        Form simple("Simple Form", 150, 150);
        
        std::cout << intern << std::endl;
        std::cout << simple << std::endl;
        
        intern.signForm(simple);
        std::cout << simple << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Boundary case - exact grade required ===" << std::endl;
    try {
        Bureaucrat mike("Mike", 50);
        Form boundary("Boundary Form", 50, 25);
        
        std::cout << mike << std::endl;
        std::cout << boundary << std::endl;
        
        mike.signForm(boundary);
        std::cout << boundary << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 10: Both grades invalid (sign and execute) ===" << std::endl;
    try {
        Form invalid1("Invalid Sign", 0, 50);
        std::cout << invalid1 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught on sign grade: " << e.what() << std::endl;
    }
    
    try {
        Form invalid2("Invalid Exec", 50, 200);
        std::cout << invalid2 << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught on exec grade: " << e.what() << std::endl;
    }

    return 0;
}
