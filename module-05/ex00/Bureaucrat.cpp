/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:33:26 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/04 16:00:48 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void	verifyGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) throw(GradeTooHighException, GradeTooLowException)
	: _name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor called: "
		<< _name
		<< ", "
		<< _grade
		<< std::endl;

    verifyGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException)
	: _name(instance.getName()), _grade(instance.getGrade())
{
    std::cout << "Bureaucrat copy constructor called: "
		<< this->_name
		<< ", "
		<< this->_grade
		<< std::endl;

    verifyGrade(_grade);
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException)
{
    std::cout << "Bureaucrat copy assignment operator called: "
		<< instance.getName()
		<< ", "
		<< instance.getGrade()
		<< std::endl;

    this->_grade = instance.getGrade();
    verifyGrade(_grade);
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

void    Bureaucrat::incrementGrade() throw(GradeTooHighException)
{
    this->_grade--;
    if (this->getGrade() < 1)
        throw Bureaucrat::GradeTooHighException();
}

void    Bureaucrat::decrementGrade() throw(GradeTooLowException)
{
    this->_grade++;
    if (this->getGrade() > 150)
        throw Bureaucrat::GradeTooLowException();
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
