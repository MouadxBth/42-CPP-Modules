/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:24:14 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 19:05:02 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern deconstructor called" << std::endl;
}

Intern::Intern(const Intern& instance)
{
    (void) instance;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& instance)
{
    (void) instance;
    std::cout << "Intern copy assignment operator called" << std::endl;
    return (*this);
}

static AForm *makeShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm *makePresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

static std::string toLower(std::string str)
{
    std::string result;

    for (int index = 0; index < (int)(str.length()); index++)
        result += std::tolower(str[index]);
    return (result);
}

AForm *Intern::makeForm(std::string form, std::string target)
{
    std::string name = toLower(form);

    AForm *(*functions[3])(std::string) = {
        &makeShrubberyCreationForm,
        &makeRobotomyRequestForm,
        &makePresidentialPardonForm
    };

    std::string forms[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    for (int index = 0; index < 3; index++)
    {
        if (forms[index] == name)
        {
            std::cout << "Intern creates " 
                << form 
                << std::endl;
            return (functions[index](target));
        }
    }

    std::cerr << "Error: Form " 
        << form 
        << " does not exist" 
        << std::endl;
    return NULL;
}