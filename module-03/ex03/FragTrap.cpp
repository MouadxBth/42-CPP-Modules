#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "A FragTrap has been created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &ref) : ClapTrap(ref)
{
	*this = ref;
	std::cout << "The FragTrap "
		<< "'" + ref._name + "'"
		<< " has been cloned."
		<< std::endl;

}

FragTrap	&FragTrap::operator=(const FragTrap &ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "The FragTrap "
			<< "'" + _name + "'"
			<< " has been destroyed."
			<< std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "The FragTrap "
		<< "'" + name + "'"
		<< " has been created."
		<< std::endl;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "The FragTrap "
		<< "'" + _name + "'"
		<< " is requesting a high fives :)"
		<< std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap "
			<< "'" + this->_name + "'"
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage
			<< " points of damage!" << std::endl;
	}
}
