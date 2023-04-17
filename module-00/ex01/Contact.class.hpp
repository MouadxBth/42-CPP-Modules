/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:16:35 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/11 16:29:43 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "Utilities.hpp"

const int WIDTH = 10;

class Contact
{

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact(void);
	~Contact(void);
	
	std::string getFirstName(void) const;
	void	setFirstName(std::string);

	std::string getLastName(void) const;
	void	setLastName(std::string);

	std::string getNickname(void) const;
	void	setNickname(std::string);

	std::string getPhoneNumber(void) const;
	void	setPhoneNumber(std::string);

	std::string getDarkestSecret(void) const;
	void	setDarkestSecret(std::string);

	void printContact(int) const;

	static bool isValid(Contact&);

	static Contact inputContact(void);
};
