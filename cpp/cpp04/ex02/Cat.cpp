#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    _CatBrain = new Brain();
    std::cout << "Cat " << this->type << " is constructed!" << std::endl;
}

Cat::Cat(const Cat &copy) {
    this->type = copy.getType();
    std::cout << "Cat " << this->type << " is constructed!" << std::endl;
}
Cat &Cat::operator=(const Cat &op) {
    if (this != &op)
        this->type = op.getType();
    std::cout << "Cat " << this->type << " is constructed!" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _CatBrain;
    std::cout << "Cat " << this->type << " is deconstructed!" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meow !!!" << std::endl;
}