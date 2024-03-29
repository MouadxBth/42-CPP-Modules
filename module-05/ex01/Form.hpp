/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:49:07 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/04 16:03:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _formSigned;
		const int _signingGrade;
		const int _executingGrade;

	public:
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Form();
		~Form();
		Form(const Form& instance) throw(GradeTooHighException, GradeTooLowException);
		Form& operator=(const Form& instance) throw(GradeTooHighException, GradeTooLowException);

		Form(const std::string name,
			const int signingGrade,
			const int executingGrade,
			bool formSigned = false) throw(GradeTooHighException, GradeTooLowException);

		const std::string getName() const;
		bool isSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;

		void	beSigned(Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException);

};


std::ostream& operator<<(std::ostream& output, const Form& instance);
