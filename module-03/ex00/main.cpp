#include "ClapTrap.hpp"


int	main(void)
{
	ClapTrap mawi("Mawi");
	ClapTrap foe("Enemy");

	std::cout << std::endl;

	mawi.attack("Enemy");
	std::cout << std::endl;

	foe.takeDamage(5);
	std::cout << std::endl;

	foe.beRepaired(10);
	std::cout << std::endl;

	foe.takeDamage(10);
	std::cout << std::endl;

	foe.takeDamage(10);
	std::cout << std::endl;

	foe.attack("Mawi");
	std::cout << std::endl;
}
