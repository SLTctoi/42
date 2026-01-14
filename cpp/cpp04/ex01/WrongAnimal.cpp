#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("") {
    std::cout << "WrongAnimal " << this->type << " is constructed!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    this->type = copy.getType();
    std::cout << "WrongAnimal " << this->type << " is constructed!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type) : type(Type) {
    std::cout << "Animal " << this->type << " is constructed!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &op) {
    if (this != &op)
        this->type = op.getType();
    std::cout << "WrongAnimal " << this->type << " is constructed!" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal " << this->type << " is deconstructed!" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return this->type;
}

void WrongAnimal::makeSound(void) const {
        std::cout << "WrongAnimal sound" << std::endl;
}