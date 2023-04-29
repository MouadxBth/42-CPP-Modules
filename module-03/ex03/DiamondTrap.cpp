
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
	ClapTrap("no_name_clap_name"),
	ScavTrap(),
	FragTrap()
{
	std::cout << "A DiamondTrap has been created." << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(),
	FragTrap()
{
	std::cout << "The DiamondTrap "
		<< "'" + name + "'"
		<< " has been created."
		<< std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap &ref) :
	ClapTrap(ref),
	ScavTrap(ref),
	FragTrap(ref)
{
	*this = ref;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "The DiamondTrap "
		<< "'" + this->_name + "'"
		<< " has been destroyed."
		<< std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ref)
{
	this->_name = ref._name;
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I'am " << this->_name << " and " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
