#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]"
              << std::endl
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]"
              << std::endl
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]"
              << std::endl
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]"
              << std::endl
              << "This is unacceptable, I want to speak to the manager now."
              << std::endl;
}

static int determineFunction(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int index = 0; index < 4; index++)
    {
        if (level == levels[index])
            return (index);
    }
    return (-1);
}

void Harl::complain(std::string level)
{
    void (Harl::*functions[])(void) = {&Harl::debug,
                                       &Harl::info,
                                       &Harl::warning,
                                       &Harl::error};
    int index = determineFunction(level);

    if (index >= 0)
        (this->*functions[index])();
}