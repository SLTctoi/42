#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    for (size_t i = 0; i < 100; i++)
        _Brain[i] = "";
    std::cout << "Brain " << this->_Brain << " is constructed!" << std::endl;
}

Brain::Brain(const Brain &copy) {
    if (this != &copy) {
        for (size_t i = 0; i < 100; i++) {
            this->_Brain[i] = copy._Brain[i];
        }
    }
    std::cout << "Brain " << this->_Brain << " is constructed!" << std::endl;
}

Brain &Brain::operator=(const Brain &op) {
    if (this != &op) {
        for (size_t i = 0; i < 100; i++) {
            this->_Brain[i] = op._Brain[i];
        }
    }
    std::cout << "Brain " << this->_Brain << " is constructed!" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain " << this->_Brain << " is deconstructed!" << std::endl;
}

void Brain::setBrain(int index, const std::string s) {
    if (index < 0 || index > 99) {
        std::cout << "100 slots in the brain, from 0 to 99" << std::endl;
        return;
    }
    this->_Brain[index] = s;
}

std::string Brain::getBrain(int index) const {
    if (index < 0 || index > 99) {
        std::cout << "100 slots in the brain, from 0 to 99" << std::endl;
        return "";
    }
    return this->_Brain[index];
}
