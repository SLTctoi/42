#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() : _Type(std::string()) {}

Weapon::Weapon(const std::string &type) : _Type(type) {}

Weapon::~Weapon() {
    std::cout << _Type << " is destroyed" << std::endl;
}

const std::string &Weapon::getType() const {
    return _Type;
}

void Weapon::setType(const std::string &type) {
    _Type = type;
}