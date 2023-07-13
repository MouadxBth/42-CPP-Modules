/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:02:59 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 15:42:25 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5),
	_target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm deconstructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& instance)
	: AForm("PresidentialPardonForm", 25, 5),
	_target(instance.getTarget())
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& instance)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &instance)
	{
		AForm::operator=(instance);
		this->_target = instance.getTarget();
	}
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	std::cout << "PresidentialPardonForm parametrized constructor called" << std::endl;
}
const std::string& PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::executeForm() const
{
	std::cout << this->_target
		<< " has been pardoned by Zaphod Beeblebrox. "
		<< std::endl;
}
