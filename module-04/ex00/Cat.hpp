#pragma once

#include "Animal.hpp"

class Cat : public Animal
{

public:
	Cat();
	Cat(Cat &);
	Cat	&operator=(const Cat &);
	~Cat();

	virtual void 	makeSound() const;
};

