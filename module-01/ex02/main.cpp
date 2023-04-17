#include <iostream>
#include <string>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";

    std::string *brainPTR = &brain;
    std::string &brainREF = brain;

    std::cout << std::endl;
    std::cout << "Memory address of the string variable: " << (void *)&brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << (void *)brainPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << (void *)&brainREF << std::endl;

    std::cout << std::endl;
    std::cout << "Value of the string variable: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *brainPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << brainREF << std::endl;
}