#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main(void)
{
	{
		std::cout << "=====================================> FIRST TEST\n" << std::endl;

		AMateria *ice, *cure;

		Character first("mawi");
		Character second("npc");

		ice = new Ice();
		cure = new Cure();

		std::cout << ice->getType() << std::endl;
		std::cout << cure->getType() << std::endl;

		ice->use(first);
		cure->use(second);

		std::cout << first.getName() << std::endl;
		std::cout << second.getName() << std::endl;

		delete (ice);
		delete (cure);
	}
	{
		std::cout << "=====================================> SECOND TEST\n" << std::endl;

		Character first("mawi");
		Character second("npc");

		std::cout << first.getName() << std::endl;

		first.equip(new Cure());
		first.equip(new Ice());
		first.equip(new Ice());
		first.equip(new Cure());

		first.unequip(3);
		first.unequip(2);

		first.use(1, second);
		first.use(0, second);

		AMateria::cleanup();
	}
	{
		std::cout << "=====================================> THIRD TEST\n" << std::endl;

		IMateriaSource* src = new MateriaSource();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
}
