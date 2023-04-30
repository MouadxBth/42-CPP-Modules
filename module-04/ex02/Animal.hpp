#pragma once

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	Animal();
	Animal(const Animal &);
	Animal(std::string);
	virtual Animal &operator=(const Animal &);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;
};
