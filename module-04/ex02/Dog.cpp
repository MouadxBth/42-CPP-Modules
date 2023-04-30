#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
	std::cout << "A Dog has been created." << std::endl;
}

Dog::Dog(Dog &ref) : Animal(ref), _brain(new Brain(*this->_brain))
{
	std::cout << "A Dog has been cloned." << std::endl;
}

Dog &Dog::operator=(const Dog &ref)
{
	*this->_brain = *ref._brain;
	this->_type = ref._type;
	std::cout << "A Dog has been created." << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "A Dog has been destroyed." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark" << std::endl;
}
