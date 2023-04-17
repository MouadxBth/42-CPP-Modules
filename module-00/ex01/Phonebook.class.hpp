/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:24:40 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/11 16:28:48 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.class.hpp"
#include "Utilities.hpp"


class Phonebook
{

private:
	int	_current;
	Contact _contacts[8];

public:
	Phonebook(void);
	~Phonebook(void);

	Contact *getContacts(void);
	void	findContact(const int);

	void	addContact(const Contact &contact);
	void	printContacts(void);

	bool	isFull(void) const;
	int		currentCount(void) const;
};
