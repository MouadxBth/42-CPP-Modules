/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:11:32 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/01 11:35:33 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string> // not necessary, iostream already contains <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& instance);
		Bureaucrat& operator=(const Bureaucrat& instance);
	
		Bureaucrat(const std::string& name, int grade);

		const std::string& getName() const;
		int getGrade() const;

		void    incrementGrade();
		void    decrementGrade();
	
		class GradeTooHighException : public std::runtime_error
		{
			public:
				GradeTooHighException(const std::string& error = "Grade too high") : runtime_error(error) {}
		};

		class GradeTooLowException : public std::runtime_error
		{
			public:
				GradeTooLowException(const std::string& error = "Grade too low") : runtime_error(error) {}
		};
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& instance);