/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:21:36 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 14:22:16 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

static void	verifyGrades(int signingGrade, int executingGrade)
{
	if (signingGrade < 1 || executingGrade < 1)
		throw Form::GradeTooHighException();
	if (signingGrade > 150 || executingGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form() :
	_name("default"),
	_formSigned(false),
	_signingGrade(1),
	_executingGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form deconstructor called: " << (*this) << std::endl;
}

Form::Form(const Form& instance) :
	_name(instance.getName()),
	_formSigned(instance.isSigned()),
	_signingGrade(instance.getSigningGrade()),
	_executingGrade(instance.getExecutingGrade())
{
	std::cout << "Form copy constructor called" << std::endl;
	verifyGrades(this->_signingGrade, this->_executingGrade);
}

Form& Form::operator=(const Form& instance)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	this->_formSigned = instance.isSigned();
	verifyGrades(instance.getSigningGrade(), instance.getExecutingGrade());
	return (*this);
}

Form::Form(const std::string name, const int signingGrade, const int executingGrade, bool formSigned) :
	_name(name),
	_formSigned(formSigned),
	_signingGrade(signingGrade),
	_executingGrade(executingGrade)
{
	verifyGrades(this->_signingGrade, this->_executingGrade);
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::isSigned() const
{
	return (this->_formSigned);
}

int Form::getSigningGrade() const
{
	return (this->_signingGrade);
}

int Form::getExecutingGrade() const
{
	return (this->_executingGrade);
}

void Form::beSigned(Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException)
{
	if (instance.getGrade() > getSigningGrade())
		throw Form::GradeTooLowException();
	this->_formSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Grade too low");
}

std::ostream& operator<<(std::ostream& output, const Form& instance)
{
    output << instance.getName()
		<< ", is signed "
		<< instance.isSigned()
		<< ", signing grade "
		<< instance.getSigningGrade()
		<< ", executing grade "
		<< instance.getExecutingGrade();
    return (output);
}
