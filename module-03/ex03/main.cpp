#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap mawi("Mawi");
	DiamondTrap clone = mawi;

	mawi.whoAmI();
	mawi.guardGate();
	mawi.highFiveGuys();

	clone.attack("Mawi");
}
