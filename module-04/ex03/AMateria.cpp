#include "AMateria.hpp"

AMateria **AMateria::dropped = NULL;

AMateria::AMateria() : _type(std::string()) {}

AMateria::AMateria(const AMateria &ref)
{
	(void) ref;
}

AMateria &AMateria::operator=(const AMateria &ref)
{
	(void) ref;
	return (*this);
}

AMateria::~AMateria()
{
}

AMateria::AMateria(const std::string &type) : _type(type) {}

const std::string &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "<AMateria> " << getType() << " * used against <name> *" << std::endl;
	(void)target;
}


void AMateria::drop()
{
	AMateria **extended_array;

	int index = 0;
	while (dropped && dropped[index])
		if (dropped[index++] == this)
			return ;

	extended_array = new AMateria*[index + 2];
	extended_array[index] = this;
	extended_array[index + 1] = NULL;

	for (int j = 0; j < index; j++)
		extended_array[j] = dropped[j];
	delete[] dropped;
	dropped = extended_array;
}

void AMateria::cleanup()
{
	int	index = -1;
	while (dropped && dropped[++index])
		delete dropped[index];
}
