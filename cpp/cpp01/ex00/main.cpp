#include "Zombie.hpp"

int main() {
    Zombie* z = newZombie("HeapZombie");
    z->announce();
    delete z;

    randomChump("StackZombie");
    return 0;
}