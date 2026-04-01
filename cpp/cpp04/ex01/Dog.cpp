#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    _DogBrain = new Brain();
    std::cout << "Dog " << this->type << " is constructed!" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
    _DogBrain = new Brain(*copy._DogBrain);
    std::cout << "Dog " << this->type << " is copied!" << std::endl;
}
Dog &Dog::operator=(const Dog &op) {
    if (this != &op) {
        Animal::operator=(op);
        delete _DogBrain;
        _DogBrain = new Brain(*op._DogBrain);
    }
    std::cout << "Dog assigned!" << std::endl;
    return *this;
}

Dog::~Dog() {
    delete _DogBrain;
    std::cout << "Dog " << this->type << " is deconstructed!" << std::endl;
}

void Dog::makeSound(void) const {
    std::cout << "Wouf !!!" << std::endl;
}

Brain* Dog::getBrain(void) const {
    return this->_DogBrain;
}