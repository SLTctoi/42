#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    for (size_t i = 0; i < 100; i++)
        ideas[i] = "";
    std::cout << "Brain is constructed!" << std::endl;
}

Brain::Brain(const Brain &copy) {
    for (size_t i = 0; i < 100; i++) {
        this->ideas[i] = copy.ideas[i];
    }
    std::cout << "Brain is copied!" << std::endl;
}

Brain &Brain::operator=(const Brain &op) {
    if (this != &op) {
        for (size_t i = 0; i < 100; i++) {
            this->ideas[i] = op.ideas[i];
        }
    }
    std::cout << "Brain assigned!" << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain is destroyed!" << std::endl;
}

void Brain::setBrain(int index, const std::string s) {
    if (index < 0 || index > 99) {
        std::cout << "100 slots in the brain, from 0 to 99" << std::endl;
        return;
    }
    this->ideas[index] = s;
}

std::string Brain::getBrain(int index) const {
    if (index < 0 || index > 99) {
        std::cout << "100 slots in the brain, from 0 to 99" << std::endl;
        return "";
    }
    return this->ideas[index];
}
