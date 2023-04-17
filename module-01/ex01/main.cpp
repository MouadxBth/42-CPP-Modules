#include "Zombie.hpp"

int main(void)
{
    int total = 10;
    Zombie *horde = zombieHorde(total, "Mawis");

    for (int index = 0; index < total; index++)
        horde[index].announce();

    delete[] horde;
}