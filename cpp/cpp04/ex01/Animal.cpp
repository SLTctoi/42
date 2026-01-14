#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("") {
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}

Animal::Animal(std::string Type) : type(Type) {
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}

Animal::Animal(const Animal &copy) {
    this->type = copy.getType();
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}
Animal &Animal::operator=(const Animal &op) {
    if (this != &op)
        this->type = op.getType();
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal " << this->type << " is deconstructed!" << std::endl;
}

std::string Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) const {
        std::cout << "Animal sound" << std::endl;
}