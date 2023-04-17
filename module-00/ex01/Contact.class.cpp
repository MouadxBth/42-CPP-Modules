/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:30:06 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/11 16:30:30 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"

Contact::Contact(void) : _firstName(std::string()),
                         _lastName(std::string()),
                         _nickname(std::string()),
                         _phoneNumber(std::string()),
                         _darkestSecret(std::string())
{
    return;
}

Contact::~Contact(void)
{
    return;
}

std::string Contact::getFirstName(void) const
{
    return (this->_firstName);
}

void Contact::setFirstName(std::string firstName)
{
    this->_firstName = firstName;
}

std::string Contact::getLastName(void) const
{
    return (this->_lastName);
}

void Contact::setLastName(std::string lastName)
{
    this->_lastName = lastName;
}

std::string Contact::getNickname(void) const
{
    return (this->_nickname);
}

void Contact::setNickname(std::string nickname)
{
    this->_nickname = nickname;
}

std::string Contact::getPhoneNumber(void) const
{
    return (this->_phoneNumber);
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
    this->_phoneNumber = phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
    return (this->_darkestSecret);
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
    this->_darkestSecret = darkestSecret;
}

static std::string truncate(std::string str, size_t width)
{
    if (str.length() < width)
        return (str);
    return (str.erase(width - 1, str.length() - (width - 1))
            .append("."));
} 

void Contact::printContact(int index) const
{
    std::cout << "|" << std::setw(WIDTH) << index;

    std::cout << "|" << std::setw(WIDTH) << ((this->_firstName.length() > WIDTH) 
            ? truncate(this->_firstName, WIDTH)
            : this->_firstName);

    std::cout << "|" << std::setw(WIDTH) << ((this->_lastName.length() > WIDTH) 
            ? truncate(this->_lastName, WIDTH)
            : this->_lastName);

    std::cout << "|" << std::setw(WIDTH) << ((this->_nickname.length() > WIDTH) 
            ? truncate(this->_nickname, WIDTH)
            : this->_nickname);

    std::cout << "|" << std::endl;
}

bool Contact::isValid(Contact& contact)
{
    return (!contact._firstName.empty() 
    && !contact._lastName.empty()
    && !contact._nickname.empty()
    && !contact._phoneNumber.empty()
    && !contact._darkestSecret.empty());
}

static std::string input(std::string name)
{
    std::string result;

    std::cout << GREEN << "Enter " << CYAN << name << GREEN << " : " << RESET << std::endl;
    std::getline(std::cin, result, '\n');
        
    if (std::cin.eof())
        std::cout << std::endl;
    if (result.empty())
        std::cerr << RED << name << " cannot be empty!" << RESET << std::endl;
    return (result);
}

Contact Contact::inputContact(void)
{
    Contact     result;

    result.setFirstName(input("First Name"));
    result.setLastName(input("Last Name"));
    result.setNickname(input("Nickname"));
    result.setPhoneNumber(input("Phone number"));
    result.setDarkestSecret(input("Darkest Secret"));
    return (result);
}
