#pragma once

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const FragTrap &);
	FragTrap &operator=(const FragTrap &);
	~FragTrap();

	FragTrap(std::string);

	void highFiveGuys(void);
	void attack(const std::string &);
};
