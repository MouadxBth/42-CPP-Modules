#include "ScavTrap.hpp"


int	main(void)
{
	ScavTrap mawi("Mawi");
	ScavTrap clone = mawi;

	mawi.guardGate();

	clone.attack("Mawi");
}
