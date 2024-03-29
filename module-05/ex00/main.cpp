/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 11:05:37 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/04 15:49:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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

	std::cout << "\n"<< defaultBureaucrat << "\n" << first << "\n"
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
		<< "\tNo other exception should be thrown\n"
		<< std::endl;
	ft_print_separator();

	try
	{
		Bureaucrat	bureaucrat("bureaucrat", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << "X) " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	bureaucrat("bureaucrat", 151);
	}
	catch (std::exception & e)
	{
		std::cerr << "X) " << e.what() << std::endl;
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
		std::cerr << "X) " << e.what() << std::endl;
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
		std::cerr << "X) " << e.what() << std::endl;
	}

	std::cout << std::endl;
}

int main()
{
	ft_first();
	ft_second();
	ft_third();
	return (0);
}
