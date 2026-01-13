#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("") {
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}

Animal::Animal(const Animal &copy) {
    this->type = copy.getType();
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}
Animal &Animal::operator=(const Animal &other) {
    this->type = other.getType();
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal " << this->type << " is deconstructed!" << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) {
    if (this->type == "")
        std::cout << "Animal sound" << std::endl;
}