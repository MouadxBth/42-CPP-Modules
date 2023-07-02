/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:33:26 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/01 11:48:27 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance) : name(instance.getName()), grade(instance.getGrade())
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& instance)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    this->grade = instance.getGrade();
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat deconstructor called" << std::endl;
}

void    Bureaucrat::incrementGrade()
{
    this->grade--;
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::decrementGrade()
{
    this->grade++;
    if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
}

const std::string& Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& instance)
{
    output << instance.getName() << ", grade " << instance.getGrade();
    return (output);
}