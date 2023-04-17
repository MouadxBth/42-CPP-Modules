/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:49:09 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/11 20:49:52 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "Phonebook.class.hpp"
#include <limits>

static void add(Phonebook &book)
{
    if (book.isFull())
        std::cout << "Phone book is full! overwriting first contact.." << std::endl;
    Contact contact = Contact::inputContact();

    if (Contact::isValid(contact))
        book.addContact(contact);
    else
        std::cerr << "Invalid Contact!" << std::endl;
}

static void search(Phonebook &book)
{
    int index;

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

int main(void)
{
    Phonebook book;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command:" << std::endl;
        std::getline(std::cin, command, '\n');

        if (std::cin.eof())
            return (std::cout << std::endl, 1);

        if (command == "ADD")
            add(book);
        else if (command == "SEARCH")
            search(book);
        else if (command == "EXIT")
            return (std::cout << "Bye!" << std::endl, 0);
        else
            std::cerr << "Unknown command!" << std::endl;
    }

    return (0);
}
