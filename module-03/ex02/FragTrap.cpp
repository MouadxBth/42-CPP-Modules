#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "FragTrap is born" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << name << " FragTrap is born" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &to_cpy)
{
	std::cout << "FragTrap is born" << std::endl;
	*this = to_cpy;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name << " FragTrap was destroyed by the angry compilo" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref.damage;
	return (*this);
}

void	FragTrap::highFiveGuys(void)
{
	if (this->energy > 0 && this->health > 0)
		std::cout << this->name << " : Please can we HighFive guys ?" << std::endl;
}
