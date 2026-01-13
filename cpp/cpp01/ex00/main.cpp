#include "Zombie.hpp"

int main() {
    // fonctionne comme alloc
    Zombie* z = newZombie("HeapZombie");
    z->announce();
    delete z;

    // var classique vit dans la fonction
    randomChump("StackZombie");
    return 0;
}