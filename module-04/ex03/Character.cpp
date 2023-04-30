#include "Character.hpp"

Character::Character() : _name("default")
{
	for (int index = 0; index < 4; index++)
		_inventory[index] = NULL;
}

Character::Character(const Character &ref) : _name(ref._name)
{
	for (int index = 0; index < 4; index++)
		_inventory[index] = ref._inventory[index];
}

Character &Character::operator=(const Character &ref)
{
	delete[] (*_inventory);
	this->_name = ref._name;
	for (int index = 0; index < 4; index++)
		_inventory[index] = ref._inventory[index];
	return (*this);
}

Character::~Character()
{
	for (int index = 0; index < 4; index++)
		if (_inventory[index])
			delete _inventory[index];
}

Character::Character(std::string name) :_name(name)
{
	for (int index = 0; index < 4; index++)
		_inventory[index] = NULL;
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria *materia)
{
	for (int index = 0; index < 4; index++)
	{
		if (!_inventory[index])
		{
			_inventory[index] = materia;
			return ;
		}
	}
}

void Character::unequip(int index)
{
	if (index < 0 || index > 3)
		return ;
	AMateria *temp = _inventory[index];
	if (!temp)
		return ;
	temp->drop();
	_inventory[index] = NULL;
}

void Character::use(int index, ICharacter &character)
{
	if (index < 0 || index > 3)
		return ;
	if (_inventory[index])
		_inventory[index]->use(character);
}
