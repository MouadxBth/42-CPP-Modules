#pragma once

#include "Animal.hpp"

class Dog : public Animal
{

public:
	Dog();
	Dog(Dog &);
	Dog	&operator=(const Dog &);
	~Dog();

	virtual void 	makeSound() const;
};

