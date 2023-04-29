#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{

private:
	std::string _name;
    Weapon& _weapon;

public:
    HumanA(std::string, Weapon&);
    ~HumanA(void);

    void attack(void) const;
};
