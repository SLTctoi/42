#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Creating valid bureaucrats ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        
        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;
        
        Bureaucrat charlie("Charlie", 150);
        std::cout << charlie << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Incrementing grade (improving) ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 3);
        std::cout << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
        dave.incrementGrade();
        std::cout << "After increment: " << dave << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrementing grade (worsening) ===" << std::endl;
    try {
        Bureaucrat eve("Eve", 148);
        std::cout << eve << std::endl;
        eve.decrementGrade();
        std::cout << "After decrement: " << eve << std::endl;
        eve.decrementGrade();
        std::cout << "After decrement: " << eve << std::endl;
        eve.decrementGrade();
        std::cout << "After decrement: " << eve << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
    try {
        Bureaucrat frank("Frank", 75);
        std::cout << frank << std::endl;
        Bureaucrat frank_copy(frank);
        std::cout << frank_copy << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Assignment operator ===" << std::endl;
    try {
        Bureaucrat george("George", 100);
        Bureaucrat henry("Henry", 50);
        std::cout << "Before: " << george << std::endl;
        std::cout << "Before: " << henry << std::endl;
        george = henry;
        std::cout << "After assignment: " << george << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Negative grade ===" << std::endl;
    try {
        Bureaucrat negative("Negative", -1);
        std::cout << negative << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 9: Very high invalid grade ===" << std::endl;
    try {
        Bureaucrat toohigh("TooHigh", 200);
        std::cout << toohigh << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
