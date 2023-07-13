/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:21:36 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 18:06:44 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

static void	verifyGrades(int signingGrade, int executingGrade)
{
	if (signingGrade < 1 || executingGrade < 1)
		throw AForm::GradeTooHighException();
	if (signingGrade > 150 || executingGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm() :
	_name("default"),
	_formSigned(false),
	_signingGrade(1),
	_executingGrade(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm deconstructor called: " << (*this) << std::endl;
}

AForm::AForm(const AForm& instance) :
	_name(instance.getName()),
	_formSigned(instance.isSigned()),
	_signingGrade(instance.getSigningGrade()),
	_executingGrade(instance.getExecutingGrade())
{
	std::cout << "AForm copy constructor called" << std::endl;
	verifyGrades(this->_signingGrade, this->_executingGrade);
}

AForm& AForm::operator=(const AForm& instance)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	this->_formSigned = instance.isSigned();
	verifyGrades(instance.getSigningGrade(), instance.getExecutingGrade());
	return (*this);
}

AForm::AForm(const std::string name, const int signingGrade, const int executingGrade, bool formSigned) :
	_name(name),
	_formSigned(formSigned),
	_signingGrade(signingGrade),
	_executingGrade(executingGrade)
{
	verifyGrades(this->_signingGrade, this->_executingGrade);
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::isSigned() const
{
	return (this->_formSigned);
}

int AForm::getSigningGrade() const
{
	return (this->_signingGrade);
}

int AForm::getExecutingGrade() const
{
	return (this->_executingGrade);
}

void AForm::beSigned(Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException)
{
	if (instance.getGrade() > getSigningGrade())
		throw AForm::GradeTooLowException();
	this->_formSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException: Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException: Grade too low");
}

std::ostream& operator<<(std::ostream& output, const AForm& instance)
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

void AForm::execute(const Bureaucrat& instance) const throw(GradeTooLowException, std::runtime_error)
{
	if (instance.getGrade() > this->_executingGrade)
		throw (GradeTooLowException());
	else if (!isSigned())
		throw (std::runtime_error("Form is not signed!"));
	else
		executeForm();
}
