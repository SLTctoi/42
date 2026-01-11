#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
    _Name = name;
}

Zombie::~Zombie() {
    std::cout << _Name << " is destroyed" << std::endl;
}

void Zombie::announce( void ) {
    std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}