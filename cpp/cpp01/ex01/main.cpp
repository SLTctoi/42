#include "Zombie.hpp"

int main() {
    int N = 5;
    Zombie* horde = zombieHorde(N, "Horde");
    if (horde) {
        for (int i = 0; i < N; ++i)
            horde[i].announce();
        delete[] horde;
    }

    return 0;
}