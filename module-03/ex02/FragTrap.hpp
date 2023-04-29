#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

private:

public:
	FragTrap();
	FragTrap(std::string);
	FragTrap(FragTrap &);
	~FragTrap();

	FragTrap	&operator=(const FragTrap &);

	void	highFiveGuys();
};
