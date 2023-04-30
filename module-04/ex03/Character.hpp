#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{

private:
	AMateria *_inventory[4];
	std::string _name;

public:
	Character();
	Character(const Character &);
	Character &operator=(const Character &);
	~Character();

	Character(std::string);

	std::string const & getName() const;

	virtual void equip(AMateria *);
	virtual void unequip(int);
	virtual void use(int, ICharacter &);
};
