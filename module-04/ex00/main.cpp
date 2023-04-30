#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "=====================================> FIRST TEST\n" << std::endl;
		Animal	animal;
		Animal	*dog = new Dog();
		Animal	*cat = new Cat();

		std::cout << animal.getType() << std::endl;
		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;

		animal.makeSound();
		dog->makeSound();
		cat->makeSound();

		delete(dog);
		delete(cat);
	}

	{
		std::cout << "=====================================> SECOND TEST\n" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete(meta);
		delete(j);
		delete(i);
	}

	{
		std::cout << "=====================================> THIRD TEST\n" << std::endl;
		const Animal* animal = new Animal();
		const WrongAnimal* wrongAnimal = new WrongAnimal();

		const Animal* cat = new Cat();
		const WrongAnimal* wrongCat = new WrongCat();

		std::cout << animal->getType() << " " << std::endl;
		std::cout << wrongAnimal->getType() << " " << std::endl;

		std::cout << cat->getType() << " " << std::endl;
		std::cout << wrongCat->getType() << " " << std::endl;

		animal->makeSound();
		wrongAnimal->makeSound();

		cat->makeSound();
		wrongCat->makeSound();

		delete(animal);
		delete(wrongAnimal);

		delete(cat);
		delete(wrongCat);
	}

	return (0);
}
