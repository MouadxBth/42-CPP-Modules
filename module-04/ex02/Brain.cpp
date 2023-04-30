#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "A Brain has been created." << std::endl;
}

Brain::~Brain()
{
	std::cout << "A Brain has been destroyed." << std::endl;
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
	std::cout << "A Brain has been cloned." << std::endl;
}

Brain &Brain::operator=(const Brain &ref)
{
	for (int index = 0; index < 100; index++)
		this->ideas[index] = ref.ideas[index];
	std::cout << "A Brain has been cloned." << std::endl;
	return (*this);
}
