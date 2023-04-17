#pragma once

#include <string>
#include <iostream>

class Harl
{

private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl(void);
    ~Harl(void);
    void complain(std::string);
    void callFunctions(void (Harl::*functions[])(void), int);
};