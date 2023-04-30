#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int index = 0; index < 4; index++)
		_materias[index] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &ref)
{
	for (int index = 0; index < 4; index++)
	{
		delete _materias[index];
		_materias[index] = ref._materias[index];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &ref)
{
	delete[] *_materias;
	for (int index = 0; index < 4; index++)
		_materias[index] = ref._materias[index];
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int index = 0; index < 4; index++)
		delete _materias[index];
}

void MateriaSource::learnMateria(AMateria *value)
{
	for (int index = 0; index < 4; index++)
	{
		if (!_materias[index])
		{
			_materias[index] = value;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int index = 0; index < 4; index++)
	{
		if (_materias[index] && _materias[index]->getType() == type)
			return (_materias[index]->clone());
	}
	return (0);
}
