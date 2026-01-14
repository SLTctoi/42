#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog " << this->type << " is constructed!" << std::endl;
}

Dog::Dog(const Dog &copy) {
    this->type = copy.getType();
    std::cout << "Dog " << this->type << " is constructed!" << std::endl;
}
Dog &Dog::operator=(const Dog &op) {
    if (this != &op)
        this->type = op.getType();
    std::cout << "Dog " << this->type << " is constructed!" << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog " << this->type << " is deconstructed!" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Wouf !!!" << std::endl;
}