#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB
{

private:
    std::string _name;
    Weapon *_weapon;

public:
    HumanB(std::string);
    ~HumanB(void);

    void setWeapon(Weapon&);
    void attack(void) const;
};