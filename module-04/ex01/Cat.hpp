#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

private:
	Brain *_brain;

public:
	Cat();
	Cat(Cat &);
	Cat	&operator=(const Cat &);
	~Cat();

	virtual void 	makeSound() const;
};

