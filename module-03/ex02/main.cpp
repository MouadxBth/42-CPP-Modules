#include "FragTrap.hpp"

int	main(void)
{
	FragTrap mawi("Mawi");
	FragTrap clone = mawi;

	mawi.highFiveGuys();

	clone.attack("Mawi");
}
