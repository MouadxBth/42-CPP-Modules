#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(std::string()),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "A ClapTrap has been created." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0)
{
	std::cout << "The ClapTrap "
		<< "'" + name + "'"
		<< " has been created."
		<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ref) : _name(ref._name),
	_hitPoints(ref._hitPoints),
	_energyPoints(ref._energyPoints),
	_attackDamage(ref._attackDamage)
{
	std::cout << "The ClapTrap "
		<< "'" + ref._name + "'"
		<< " has been cloned."
		<< std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "The ClapTrap "
		<< "'" + this->_name + "'"
		<< " has been destroyed."
		<< std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ref)
{
	if (this != &ref)
	{
		this->_name = ref._name;
		this->_hitPoints = ref._hitPoints;
		this->_energyPoints = ref._energyPoints;
		this->_attackDamage = ref._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap "
			<< "'" + this->_name + "'"
			<< " attacks "
			<< target
			<< ", causing "
			<< this->_attackDamage
			<< " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_hitPoints -= amount;
		std::cout << "ClapTrap "
			<< "'" + this->_name + "'"
			<< " was attacked and lost "
			<< amount
			<< " health points!."
			<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints > 0 && this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap "
			<< "'" + this->_name + "'"
			<< " has repaired itself gaining "
			<< amount
			<< " health points!."
			<< std::endl;
	}
}
