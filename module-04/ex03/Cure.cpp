#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure & ref) : AMateria(ref.getType()) {}

Cure &Cure::operator=(const Cure &ref)
{
	(void) ref;
	return (*this);
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &character)
{
	std::cout <<  "* heals " << character.getName() <<"'s wounds *" << std::endl;
}
