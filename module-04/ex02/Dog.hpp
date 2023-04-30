#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

private:
	Brain *_brain;

public:
	Dog();
	Dog(Dog &);
	Dog	&operator=(const Dog &);
	~Dog();

	virtual void 	makeSound() const;
};

