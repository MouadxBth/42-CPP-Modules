#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "A ScavTrap has been created." << std::endl;
}

ScavTrap::ScavTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "The ScavTrap "
		<< "'" + name + "'"
		<< " has been created."
		<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap &ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	std::cout << "The ScavTrap "
		<< "'" + ref._name + "'"
		<< " has been cloned."
		<< std::endl;

}

ScavTrap::~ScavTrap()
{
	std::cout << "The ScavTrap "
			<< "'" + _name + "'"
			<< " has been destroyed."
			<< std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
		std::cout << "The ScavTrap "
		<< "'" + _name + "'"
		<< " is now in Gate keeper mode."
		<< std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap "
			<< "'" + this->_name + "'"
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage
			<< " points of damage!" << std::endl;
	}
}
