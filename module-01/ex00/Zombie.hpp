#pragma once

#include <iostream>
#include <string>

class Zombie
{
  private:
	std::string _name;

  public:
	Zombie(std::string);
	~Zombie(void);
	void announce(void);
};

Zombie	*newZombie(std::string);

void	randomChump(std::string);
