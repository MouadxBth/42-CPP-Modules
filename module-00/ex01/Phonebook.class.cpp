/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:38:57 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/11 16:39:02 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.class.hpp"

Phonebook::Phonebook(void)
{
    this->_current = 0;
    return;
}

Phonebook::~Phonebook(void)
{
    return;
}

Contact *Phonebook::getContacts(void)
{
    return (this->_contacts);
}

static void printFullContact(const Contact& contact)
{
    std::cout << GREEN << "Full info: \n" << RESET << std::endl;
    std::cout << CYAN << "First name: " << RESET << contact.getFirstName() << std::endl;
    std::cout << CYAN  << "Last name: " << RESET << contact.getLastName() << std::endl;
    std::cout << CYAN  << "Nickname: "  << RESET<< contact.getNickname() << std::endl;
    std::cout << CYAN  << "Phone number: "  << RESET << contact.getPhoneNumber() << std::endl;
    std::cout << CYAN  << "Darkest secret: "  << RESET << contact.getDarkestSecret() << "\n" << std::endl;
}

void Phonebook::findContact(const int index)
{
    if (index < 0 || index > this->_current || !Contact::isValid(_contacts[index])) {
        std::cerr << RED << "Contact was not found!" << RESET << std::endl;
        return ;
    }
    printFullContact(_contacts[index]);
}

void Phonebook::addContact(const Contact &contact)
{
    if (_current > 7)
        _current = 0;
    _contacts[_current] = contact;
    _current++;
}

static void printSeparator(void)
{
    std::cout << "|";
    
    for (int j = 1; j < 44; j++)
    {
        if (!(j % 11))
            std::cout << "|";
        else
            std::cout << "-";
    }
    
    std::cout << "|" << std::endl;
}

void Phonebook::printContacts(void)
{
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    printSeparator();

    for (int i = 0; i < 8; i++)
    {
        if (!Contact::isValid(_contacts[i]))
            break;
        _contacts[i].printContact(i);
        printSeparator();
    }
}

bool Phonebook::isFull(void) const
{
    return (this->_current > 7);
}

int Phonebook::currentCount(void) const
{
    return (this->_current);
}