/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:32:37 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 15:51:30 by mbouthai         ###   ########.fr       */
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

void ShrubberyCreationForm::executeForm() const
{
	std::ofstream file(this->_target + "_shrubbery");

	if (!file)
	{
		std::cerr << "Error creating file: " << this->_target << std::endl;
		return ;
	}
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << this->_target << std::endl;
        return;
    }

    file << "       ccee88oo\n";
    file << "    C8O8O8Q8PoOb o8oo\n";
    file << " dOB69QO8PdUOpugoO9bD\n";
    file << "CgggbU8OU qOp qOdoUOdcb\n";
    file << "      6OuU  /p u gcoUodpP\n";
    file << "        \\\\\\//  /douUP\n";
    file << "          \\\\\\////\n";
    file << "            |||/\\\n";
    file << "            |||\\/\\\n";
    file << "            ||||||\n";
    file << "MAWI  ......//||||\\...\n";

    file.close();

    std::cout << "Shrubbery generated and saved to: " << this->_target << std::endl;
}
