#pragma once

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &);
	Brain &operator=(const Brain &);
	virtual ~Brain();
};
