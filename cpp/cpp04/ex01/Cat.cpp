#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    _CatBrain = new Brain();
    std::cout << "Cat " << this->type << " is constructed!" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy) {
    _CatBrain = new Brain(*copy._CatBrain);
    std::cout << "Cat " << this->type << " is copied!" << std::endl;
}
Cat &Cat::operator=(const Cat &op) {
    if (this != &op) {
        Animal::operator=(op);
        delete _CatBrain;
        _CatBrain = new Brain(*op._CatBrain);
    }
    std::cout << "Cat assigned!" << std::endl;
    return *this;
}

Cat::~Cat() {
    delete _CatBrain;
    std::cout << "Cat " << this->type << " is deconstructed!" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meow !!!" << std::endl;
}

Brain* Cat::getBrain(void) const {
    return this->_CatBrain;
}