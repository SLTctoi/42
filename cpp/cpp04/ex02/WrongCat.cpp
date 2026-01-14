#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat") {
    std::cout << "WrongCat " << this->type << " is constructed!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
    std::cout << "WrongCat " << this->type << " is copied!" << std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &op) {
    if (this != &op)
        this->type = op.getType();
    std::cout << "WrongCat " << this->type << " is constructed!" << std::endl;
    return *this;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat " << this->type << " is deconstructed!" << std::endl;
}

void WrongCat::makeSound(void) const {
    std::cout << "Meow !!!" << std::endl;
}