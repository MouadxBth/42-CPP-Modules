/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:33:26 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/09 16:40:26 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: _name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor called: "
		<< _name
		<< ", "
		<< _grade
		<< std::endl;

    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance)
	: _name(instance.getName()), _grade(instance.getGrade())
{
    std::cout << "Bureaucrat copy constructor called: "
		<< this->_name
		<< ", "
		<< this->_grade
		<< std::endl;

    if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& instance)
{
    std::cout << "Bureaucrat copy assignment operator called: "
		<< instance.getName()
		<< ", "
		<< instance.getGrade()
		<< std::endl;

    this->_grade = instance.getGrade();
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat deconstructor called: "
		<< this->_name
		<< ", "
		<< this->_grade
		<< std::endl;
}

void    Bureaucrat::incrementGrade()
{
    if (this->getGrade() - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (this->getGrade() + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

const std::string& Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("GradeTooHighException: Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("GradeTooLowException: Grade too low");
}

std::ostream& operator<<(std::ostream& output, const Bureaucrat& instance)
{
    output << instance.getName()
		<< ", bureaucrat grade "
		<< instance.getGrade();
    return (output);
}
