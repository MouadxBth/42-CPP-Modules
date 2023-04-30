#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(WrongCat &);
	~WrongCat();

	WrongCat &operator=(const WrongCat &);

	void makeSound() const;
};
