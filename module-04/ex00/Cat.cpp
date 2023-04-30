#include "Cat.hpp"

Cat::Cat()
	: Animal("Cat")
{
	std::cout << "A Cat has been created." << std::endl;
}

Cat::Cat(Cat &ref) : Animal(ref)
{
	std::cout << "A Cat has been cloned." << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
	this->_type = ref._type;
	std::cout << "A Cat has been cloned." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "A Cat has been destroyed." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
