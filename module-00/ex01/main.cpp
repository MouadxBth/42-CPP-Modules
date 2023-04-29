/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:49:09 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/28 20:52:20 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "Phonebook.class.hpp"
#include <limits>

static bool	add(Phonebook &book)
{
	Contact	contact;

	if (book.isFull())
		std::cout << "Phone book is full! overwriting first contact.." << std::endl;
	contact = Contact::inputContact();
	if (Contact::isValid(contact))
		return (book.addContact(contact), true);
	else
		return (std::cerr << "Invalid Contact!" << std::endl, false);
}

static void	search(Phonebook &book)
{
	int	index;

	book.printContacts();
	std::cout << "Input the desired index: ";
	while (!(std::cin >> index) || (index < 0 || index > book.currentCount()))
	{
		if (std::cin.eof())
			break ;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Invalid Index" << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	book.findContact(index);
}

static void	print_header(void)
{
	std::cout << '\n' << "->> PhoneBook <<-" << '\n' << std::endl;
}

static void	print_menu(void)
{
	std::cout << "Supported commands:\n\n";
	std::cout << "	* ADD: 'save a new contact'\n";
	std::cout << "		(Supported contact fields are: first name, last name, nickname, phone number, and darkest secret)\n\n";
	std::cout << "	* SEARCH: 'display a specific contact'\n\n";
	std::cout << "	* EXIT: 'The program quits and the contacts are lost forever!'\n\n";
}

int	main(void)
{
	Phonebook	book;

	std::string command;
	while (true)
	{
		print_header();
		print_menu();
		std::cout << "Enter a command:" << std::endl;
		std::getline(std::cin, command, '\n');
		if (std::cin.eof())
			return (std::cout << std::endl, 1);
		if (command == "ADD")
		{
			if (!add(book))
				break ;
		}
		else if (command == "SEARCH")
			search(book);
		else if (command == "EXIT")
			return (std::cout << "Bye!" << std::endl, 0);
		else
			std::cerr << "Unknown command!" << std::endl;
	}
	return (0);
}
