#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string);
	ScavTrap(ScavTrap &);

	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &);

	void guardGate();
	void attack(const std::string &);
};
