#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
  protected:
	std::string _type;

  public:
	WrongAnimal();
	WrongAnimal(WrongAnimal &);
	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &);

	void makeSound() const;
	std::string getType() const;
};
