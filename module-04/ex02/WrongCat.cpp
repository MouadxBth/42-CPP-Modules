#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat &ref) : WrongAnimal(ref)
{
	*this = ref;
}

WrongCat::~WrongCat()
{
}

//Operator

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	this->_type = ref._type;
	return (*this);
}

//Function

void WrongCat::makeSound(void) const
{
	std::cout << "Idk what does a Wrong cat sound like..." << std::endl;
}
