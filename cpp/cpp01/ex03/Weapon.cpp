#include "Weapon.hpp"

Weapon::Weapon() {
    _type = NULL;
}

Weapon::~Weapon(){
    std::cout << _Name << " is destroyed" << std::endl;
}

std::string Weapon::getType() const {
    return _Type;
}

std::string Weapon::setType(const std::string type) {
    _Type = type;
}