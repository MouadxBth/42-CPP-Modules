#pragma once

# include <iostream>
# include <string>

class ClapTrap
{
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;

public:
	ClapTrap(void);

	ClapTrap(const ClapTrap &);

	ClapTrap(std::string);

	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &);

	void	attack(const std::string& target);

	void	takeDamage(unsigned int amount);

	void	beRepaired(unsigned int amount);
};
