#pragma once

#include <string>

class Weapon
{
private:
    std::string _type;

public:
    Weapon(std::string);
    ~Weapon(void);

    const std::string &getType(void);
    void setType(std::string);
};
