#include "Zombie.hpp"

int main(void)
{
    Zombie *mawi = newZombie("Mawi");
    mawi->announce();
    delete mawi;

    randomChump("Leon");
}