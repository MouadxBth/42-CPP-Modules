#include "Animal.hpp"

Animal::Animal() : _type(std::string())
{
	std::cout << "An Animal has been created." << std::endl;
}

Animal::Animal(const Animal &ref) : _type(ref._type)
{
	std::cout << "An Animal has been cloned." << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "An Animal of type " << type << " has been created." << std::endl;
}

Animal &Animal::operator=(const Animal &ref)
{
	this->_type = ref._type;
	std::cout << "An Animal has been cloned." << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "An Animal has been destroyed." << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Uhh? idk." << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}
