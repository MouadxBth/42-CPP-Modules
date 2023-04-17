#pragma once

#include <string>
#include <iostream>

class Zombie
{
private:
    std::string _name;

public:
    Zombie(std::string);
    Zombie(void);
    ~Zombie(void);

    void announce(void);
    void setName(std::string);
};

Zombie* zombieHorde(int, std::string);