/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:37 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/05 23:06:13 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137),
	_target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm deconstructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& instance)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(instance.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& instance)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &instance)
	{
		AForm::operator=(instance);
		this->_target = instance.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm parametrized constructor called" << std::endl;
}
const std::string& ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::executeForm() const throw(std::runtime_error)
{
	std::ofstream file((this->_target + "_shrubbery").c_str());

	if (!file)
		throw (std::runtime_error("Error creating file: " + this->_target + "_shrubbery"));


    if (!file.is_open()) 
		throw (std::runtime_error("Error opening file: " + this->_target + "_shrubbery"));

    file << "       ccee88oo\n";
    file << "    C8O8O8Q8PoOb o8oo\n";
    file << " dOB69QO8PdUOpugoO9bD\n";
    file << "CgggbU8OU qOp qOdoUOdcb\n";
    file << "      6OuU  /p u gcoUodpP\n";
    file << "        \\\\\\//  /douUP\n";
    file << "          \\\\\\////\n";
    file << "            ||M/\\\n";
    file << "            ||A\\/\\\n";
    file << "            ||W|||\n";
    file << "MAWI  ......//I|||\\...\n";

    file.close();

    std::cout << "Shrubbery generated and saved to: " << this->_target << "_shrubbery" << std::endl;
}
