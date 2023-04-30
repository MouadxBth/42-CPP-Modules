#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &ref) : AMateria(ref._type) {}

Ice &Ice::operator=(const Ice &ref)
{
	(void) ref;
	return (*this);
}

Ice::~Ice() {}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &character)
{
	std::cout << "* shoots an ice bolt at "<< character.getName() << " *" << std::endl;
}
