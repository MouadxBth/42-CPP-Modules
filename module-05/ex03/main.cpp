/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:49:42 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 19:22:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

static void ft_print_separator(int current = 0, int length = 128)
{
	int index = -1;
	std::cout << (current ? "\n" : "");
	if (current)
		std::cout << current << ")";
	while (++index < length - (current != 0))
		std::cout << "=";
	std::cout << "\n" << std::endl;
}

static void ft_first()
{
	ft_print_separator(1);
	std::cout << "=> Testing:\n"
		<< "\tDefault constructor\n"
		<< "\tParameterized constructor (highest grade)\n"
		<< "\tCopy constructor\n"
		<< "\tParameterized constructor (random grade)\n"
		<< "\tParameterized constructor (lowest grade)\n"
		<< "=> Expecting:\n"
		<< "\tNo exceptions should be thrown\n"
		<< std::endl;
	ft_print_separator();

	Bureaucrat defaultBureaucrat;
	Bureaucrat first("First", 1);
	Bureaucrat firstClone(first);
	Bureaucrat second("Second", 56);
	Bureaucrat third("Third", 150);

	std::cout << "\n" << first << "\n"
		<< firstClone << "\n"
		<< second << "\n"
		<< third << "\n"
		<< std::endl;
}

static void ft_second()
{
	ft_print_separator(2);
	std::cout << "=> Testing:\n"
		<< "\tParameterized constructor (higher than the highest grade)\n"
		<< "\tParameterized constructor (lower than the lowest grade)\n"
		<< "=> Expecting:\n"
		<< "\tParameterized constructor (higher than the highest grade) - Should throw a GradeTooHighException\n"
		<< "\tParameterized constructor (lower than the lowest grade) - Should throw a GradeTooLowException\n"
		<< "\tNo other test should throw an exception\n"
		<< std::endl;
	ft_print_separator();

	try
	{
		Bureaucrat	bureaucrat("bureaucrat", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat("bureaucrat", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

static void ft_third()
{
	ft_print_separator(3);
	std::cout << "=> Testing:\n"
		<< "\tIncrementing Bureaucrat (highest grade)\n"
		<< "\tIncrementing Bureaucrat (random grade)\n"
		<< "\tIncrementing Bureaucrat (lowest grade)\n"
		<< "\n"
		<< "\tDecrementing Bureaucrat (highest grade)\n"
		<< "\tDecrementing Bureaucrat (random grade)\n"
		<< "\tDecrementing Bureaucrat (lowest grade)\n"
		<< "=> Expecting:\n"
		<< "\tIncrementing Bureaucrat (highest grade) - Should throw a GradeTooHighException\n"
		<< "\tDecrementing Bureaucrat (lowest grade) - Should throw a GradeTooLowException\n"
		<< "\tNo other test should throw an exception\n"
		<< std::endl;
	ft_print_separator();

	Bureaucrat first("First", 1);
	Bureaucrat second("Second", 56);
	Bureaucrat third("Third", 150);

	std::cout << "\n" << first << "\n"
		<< second << "\n"
		<< third << "\n"
		<< std::endl;

	std::cout << "Incrementing:\n\n";
	try
	{
		std::cout << "Attempting to increment: " << first << "..." << std::endl;
		first.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	second.incrementGrade();
	std::cout << second << "\n";

	third.incrementGrade();
	std::cout << third << "\n";

	std::cout << "\nDecrementing:\n\n";

	first.decrementGrade();
	std::cout << first << "\n";

	second.decrementGrade();
	std::cout << second << "\n";

	third.decrementGrade();

	try
	{
		std::cout << "Attempting to decrement: " << third << "..." << std::endl;
		third.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
}

static void ft_fourth()
{
	ft_print_separator(4);
	std::cout << "=> Testing:\n"
		<< "*Part one:\n"
		<< "\tShrubberyCreationForm Default constructor\n"
		<< "\tParameterized constructor (string: test)\n"
		<< "\tCopy constructor\n"
		<< "\tParameterized constructor (string: <EMPTY>)\n\n"
		<< "*Part two:\n"
		<< "\tExecuting unsigned ShrubberyCreationForm (default)\n"
		<< "\tExecuting unsigned ShrubberyCreationForm (string: test)\n"
		<< "\tExecuting unsigned ShrubberyCreationForm (clone)\n"
		<< "\tExecuting unsigned ShrubberyCreationForm (string: <EMPTY>)\n\n"
		<< "*Part three:\n"
		<< "\tExecuting signed ShrubberyCreationForm (default)\n"
		<< "\tExecuting signed ShrubberyCreationForm (string: test)\n"
		<< "\tExecuting signed ShrubberyCreationForm (clone)\n"
		<< "\tExecuting signed ShrubberyCreationForm (string: <EMPTY>)\n"
		<< "=> Expecting:\n"
		<< "*Part one:\n"
		<< "\tNo exceptions should be thrown\n"
		<< "*Part two:\n"
		<< "\tAll tests should fail\n"
		<< "*Part three:\n"
		<< "\tAll tests should pass\n"
		<< std::endl;
	ft_print_separator();

	Bureaucrat bureaucrat("Mawi", 1);

	std::cout << "Part one:\n" << std::endl;

	ShrubberyCreationForm first;
	ShrubberyCreationForm second("test");
	ShrubberyCreationForm secondClone(second);
	ShrubberyCreationForm third("");

	std::cout << "\nPart two:\n" << std::endl;

	bureaucrat.executeForm(first);
	bureaucrat.executeForm(second);
	bureaucrat.executeForm(secondClone);
	bureaucrat.executeForm(third);

	std::cout << "\nPart three:\n" << std::endl;

	bureaucrat.signForm(first);
	bureaucrat.signForm(second);
	bureaucrat.signForm(secondClone);
	bureaucrat.signForm(third);

	bureaucrat.executeForm(first);
	bureaucrat.executeForm(second);
	bureaucrat.executeForm(secondClone);
	bureaucrat.executeForm(third);
}
static void ft_fifth()
{
	ft_print_separator(5);
	std::cout << "=> Testing:\n"
		<< "*Part one:\n"
		<< "\tRobotomyRequestForm Default constructor\n"
		<< "\tParameterized constructor (string: test)\n"
		<< "\tCopy constructor\n"
		<< "\tParameterized constructor (string: <EMPTY>)\n\n"
		<< "*Part two:\n"
		<< "\tExecuting unsigned RobotomyRequestForm (default)\n"
		<< "\tExecuting unsigned RobotomyRequestForm (string: test)\n"
		<< "\tExecuting unsigned RobotomyRequestForm (clone)\n"
		<< "\tExecuting unsigned RobotomyRequestForm (string: <EMPTY>)\n\n"
		<< "*Part three:\n"
		<< "\tExecuting signed RobotomyRequestForm (default)\n"
		<< "\tExecuting signed RobotomyRequestForm (string: test)\n"
		<< "\tExecuting signed RobotomyRequestForm (clone)\n"
		<< "\tExecuting signed RobotomyRequestForm (string: <EMPTY>)\n"
		<< "=> Expecting:\n"
		<< "*Part one:\n"
		<< "\tNo exceptions should be thrown\n"
		<< "*Part two:\n"
		<< "\tAll tests should fail\n"
		<< "*Part three:\n"
		<< "\tAll tests should pass\n"
		<< std::endl;
	ft_print_separator();

	Bureaucrat bureaucrat("Mawi", 1);

	std::cout << "Part one:\n" << std::endl;

	RobotomyRequestForm first;
	RobotomyRequestForm second("test");
	RobotomyRequestForm secondClone(second);
	RobotomyRequestForm third("");

	std::cout << "\nPart two:\n" << std::endl;

	bureaucrat.executeForm(first);
	
	bureaucrat.executeForm(second);
	bureaucrat.executeForm(secondClone);
	bureaucrat.executeForm(third);

	std::cout << "\nPart three:\n" << std::endl;

	bureaucrat.signForm(first);
	bureaucrat.signForm(second);
	bureaucrat.signForm(secondClone);
	bureaucrat.signForm(third);

	bureaucrat.executeForm(first);
	bureaucrat.executeForm(second);
	bureaucrat.executeForm(secondClone);
	bureaucrat.executeForm(third);
}
static void ft_sixth()
{
	ft_print_separator(6);
	std::cout << "=> Testing:\n"
		<< "*Part one:\n"
		<< "\tPresidentialPardonForm Default constructor\n"
		<< "\tParameterized constructor (string: test)\n"
		<< "\tCopy constructor\n"
		<< "\tParameterized constructor (string: <EMPTY>)\n\n"
		<< "*Part two:\n"
		<< "\tExecuting unsigned PresidentialPardonForm (default)\n"
		<< "\tExecuting unsigned PresidentialPardonForm (string: test)\n"
		<< "\tExecuting unsigned PresidentialPardonForm (clone)\n"
		<< "\tExecuting unsigned PresidentialPardonForm (string: <EMPTY>)\n\n"
		<< "*Part three:\n"
		<< "\tExecuting signed PresidentialPardonForm (default)\n"
		<< "\tExecuting signed PresidentialPardonForm (string: test)\n"
		<< "\tExecuting signed PresidentialPardonForm (clone)\n"
		<< "\tExecuting signed PresidentialPardonForm (string: <EMPTY>)\n"
		<< "=> Expecting:\n"
		<< "*Part one:\n"
		<< "\tNo exceptions should be thrown\n"
		<< "*Part two:\n"
		<< "\tAll tests should fail\n"
		<< "*Part three:\n"
		<< "\tAll tests should pass\n"
		<< std::endl;
	ft_print_separator();

	Bureaucrat bureaucrat("Mawi", 1);

	std::cout << "Part one:\n" << std::endl;

	PresidentialPardonForm first;
	PresidentialPardonForm second("test");
	PresidentialPardonForm secondClone(second);
	PresidentialPardonForm third("");

	std::cout << "\nPart two:\n" << std::endl;

	bureaucrat.executeForm(first);
	bureaucrat.executeForm(second);
	bureaucrat.executeForm(secondClone);
	bureaucrat.executeForm(third);

	std::cout << "\nPart three:\n" << std::endl;

	bureaucrat.signForm(first);
	bureaucrat.signForm(second);
	bureaucrat.signForm(secondClone);
	bureaucrat.signForm(third);

	bureaucrat.executeForm(first);
	bureaucrat.executeForm(second);
	bureaucrat.executeForm(secondClone);
	bureaucrat.executeForm(third);
}

static void ft_seventh()
{
	ft_print_separator(7);
	std::cout << "=> Testing:\n"
		<< "*Part one:\n"
		<< "\tIntern Default constructor\n"
		<< "\tIntern makeForm (string: shrubbery creation)\n"
		<< "\tIntern makeForm (string: ShRubBeRy CrEaTiOn)\n"
		<< "\tIntern makeForm (string: robotomy request)\n"
		<< "\tIntern makeForm (string: presidential pardon)\n"
		<< "\tIntern makeForm (string: unknown form)\n"
		<< "*Part two:\n"
		<< "\tSigning Form if it's not null (string: shrubbery creation)\n"
		<< "\tSigning Form if it's not null (string: ShRubBeRy CrEaTiOn)\n"
		<< "\tSigning Form if it's not null (string: robotomy request)\n"
		<< "\tSigning Form if it's not null (string: presidential pardon)\n"
		<< "\tSigning Form if it's not null (string: unknown form)\n"
		<< "*Part three:\n"
		<< "\tExecuting Form if it's not null (string: shrubbery creation)\n"
		<< "\tExecuting Form if it's not null (string: ShRubBeRy CrEaTiOn)\n"
		<< "\tExecuting Form if it's not null (string: robotomy request)\n"
		<< "\tExecuting Form if it's not null (string: presidential pardon)\n"
		<< "\tExecuting Form if it's not null (string: unknown form)\n"
		<< "*Part four:\n"
		<< "\tExecuting Form (string: shrubbery creation)\n"
		<< "\tExecuting Form (string: ShRubBeRy CrEaTiOn)\n"
		<< "\tExecuting Form (string: robotomy request)\n"
		<< "\tExecuting Form (string: presidential pardon)\n"
		<< "=> Expecting:\n"
		<< "*Part one:\n"
		<< "\tIntern makeForm (string: unknown form) | should not create a form and return (NULL)\n"
		<< "*Part two:\n"
		<< "\tIntern makeForm (string: unknown form) | should not sign\n"
		<< "*Part three:\n"
		<< "\tIntern makeForm (string: unknown form) | should not execute\n"
		<< "*Part four:\n"
		<< "\tDeleting all dynamically allocated forms | no error should occur\n"
		<< std::endl;
	ft_print_separator();

	Bureaucrat bureaucrat("First", 1);

	std::cout << "Part one:\n" << std::endl;

	Intern intern;

	AForm *shrubberyCreationForm = intern.makeForm("shrubbery creation", "test");
	AForm *shrubberyCreationFormUppercase = intern.makeForm("ShRubBeRy CrEaTiOn", "test");
	AForm *robotomyRequestForm = intern.makeForm("robotomy request", "test");
	AForm *presidentialPardonForm = intern.makeForm("presidential pardon", "test");
	AForm *unknownForm = intern.makeForm("unknown form", "test");

	std::cout << shrubberyCreationForm 
		<< robotomyRequestForm 
		<< presidentialPardonForm 
		<< unknownForm 
		<< std::endl;
	
	std::cout << "\nPart two:\n" << std::endl;
	if (shrubberyCreationForm)
		bureaucrat.signForm(*shrubberyCreationForm);
	if (shrubberyCreationFormUppercase)
		bureaucrat.signForm(*shrubberyCreationFormUppercase);
	if (robotomyRequestForm)
		bureaucrat.signForm(*robotomyRequestForm);
	if (presidentialPardonForm)
		bureaucrat.signForm(*presidentialPardonForm);
	if (unknownForm)
		bureaucrat.signForm(*unknownForm);

	std::cout << "Part three:\n" << std::endl;

	if (shrubberyCreationForm)
		bureaucrat.executeForm(*shrubberyCreationForm);
	if (shrubberyCreationFormUppercase)
		bureaucrat.executeForm(*shrubberyCreationFormUppercase);
	if (robotomyRequestForm)
		bureaucrat.executeForm(*robotomyRequestForm);
	if (presidentialPardonForm)
		bureaucrat.executeForm(*presidentialPardonForm);
	if (unknownForm)
		bureaucrat.executeForm(*unknownForm);

	std::cout << "\nPart four:\n" << std::endl;
	delete shrubberyCreationForm;
	delete shrubberyCreationFormUppercase;
	delete robotomyRequestForm;
	delete presidentialPardonForm;
}

int main()
{
	ft_first();
	ft_second();
	ft_third();
	ft_fourth();
	ft_fifth();
	ft_sixth();
	ft_seventh();
	return (0);
}
