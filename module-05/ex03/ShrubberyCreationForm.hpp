/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:26:35 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 17:57:13 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"

# include <iostream>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& instance);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& instance);

		ShrubberyCreationForm(std::string target);

		const std::string&	getTarget() const;

		void	executeForm() const throw(std::runtime_error);

};
