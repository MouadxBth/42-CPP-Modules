/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:11:32 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/04 16:01:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string> // not necessary, iostream already contains <string>
# include <iostream>

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;

	public:
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
		
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat& operator=(const Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException);

		Bureaucrat(const std::string& name, int grade) throw(GradeTooHighException, GradeTooLowException);

		const std::string&	getName() const;
		int	getGrade() const;

		void	incrementGrade() throw(GradeTooHighException);
		void	decrementGrade() throw(GradeTooLowException);
};

std::ostream& operator<<(std::ostream& output, const Bureaucrat& instance);
