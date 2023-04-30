#pragma once

#include <iostream>
#include <string>

class ICharacter;

class AMateria
{

private:
	static AMateria **dropped;

protected:
	const std::string _type;

public:
	AMateria();
	AMateria(const AMateria &);
	AMateria &operator=(const AMateria &);
	virtual ~AMateria();

	AMateria(const std::string &);
	const std::string &getType() const;

	virtual AMateria * clone() const = 0;
	virtual void use(ICharacter &);

	void drop();

	static void cleanup();
};
