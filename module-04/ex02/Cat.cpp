#include "Cat.hpp"

Cat::Cat() :
	Animal("Cat"),
	_brain(new Brain())
{
	std::cout << "A Cat has been created." << std::endl;
}

Cat::Cat(Cat &ref) :
	Animal(ref),
	_brain(new Brain(*ref._brain))
{
	std::cout << "A Cat has been cloned." << std::endl;
}

Cat &Cat::operator=(const Cat &ref)
{
	*this->_brain = *ref._brain;
	this->_type = ref._type;
	std::cout << "A Cat has been cloned." << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "A Cat has been destroyed." << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow" << std::endl;
}
