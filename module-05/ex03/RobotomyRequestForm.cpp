/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:27:07 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/05 23:17:07 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45),
	_target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
	
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm deconstructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& instance)
	: AForm("RobotomyRequestForm", 72, 45),
	_target(instance.getTarget())
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& instance)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &instance)
	{
		AForm::operator=(instance);
		this->_target = instance.getTarget();
	}
	
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm parametrized constructor called" << std::endl;
	
}
const std::string& RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::executeForm() const throw(std::runtime_error)
{
	if (rand() % 2 == 0)
		std::cout << this->_target
			<< " has been robotomized successfully"
			<< std::endl;
	else
		std::cout << "Failed to robotomize "
			<< this->_target
			<< std::endl;
}
