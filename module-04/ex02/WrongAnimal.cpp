#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
}

WrongAnimal::WrongAnimal(WrongAnimal &ref)
{
	*this = ref;
}

WrongAnimal::~WrongAnimal()
{
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &ref)
{
	this->_type = ref._type;
	return (*this);
}


void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}
