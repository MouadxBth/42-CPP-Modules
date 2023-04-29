#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
  private:
	std::string _name;

  public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(std::string);
	DiamondTrap(DiamondTrap &);

	DiamondTrap &operator=(const DiamondTrap &);

	void attack(const std::string &);
	void whoAmI();
};
