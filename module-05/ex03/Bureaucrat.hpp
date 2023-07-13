/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:11:32 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/13 15:48:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string> // not necessary, iostream already contains <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& instance);
		Bureaucrat& operator=(const Bureaucrat& instance);

		Bureaucrat(const std::string& name, int grade);

		const std::string& getName() const;
		int getGrade() const;

		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm& instance);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		void executeForm(const AForm& form) const;
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& instance);
