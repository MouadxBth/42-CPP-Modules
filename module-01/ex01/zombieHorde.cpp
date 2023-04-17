#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
    Zombie *horde = new Zombie[n];

    for (int index = 0; index < n; index++)
        horde[index].setName(name);
    return (horde);
}