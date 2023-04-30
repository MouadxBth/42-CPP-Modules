#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	{
		std::cout << "=====================================> FIRST TEST\n" << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j;//should not create a leak
		delete i;
	}
	{
		std::cout << "=====================================> SECOND TEST\n" << std::endl;
		int	n = 10;
		Animal*	array[n];

		for (int index = 0; index < n; ++index)
		{
			if (index % 2)
				array[index] = new Cat();
			else
				array[index] = new Dog();
		}

		for (int index = 0; index < n; ++index)
			delete (array[index]);
	}

	{
		std::cout << "=====================================> THIRD TEST\n" << std::endl;
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
		std::cout << "=====================================> FOURTH TEST\n" << std::endl;
		const Cat first;
		Cat second;

		second = first;
		first.makeSound();
	}
	return (0);
}
