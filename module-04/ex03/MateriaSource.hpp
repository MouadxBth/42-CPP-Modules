#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &);
	MateriaSource &operator=(const MateriaSource &);
	~MateriaSource();

	virtual void learnMateria(AMateria *);

	virtual AMateria *createMateria(std::string const &);
};

