/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:49:07 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/09 13:51:06 by mbouthai         ###   ########.fr       */
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
		Form();
		~Form();
		Form(const Form& instance);
		Form& operator=(const Form& instance);

		Form(const std::string name,
			const int signingGrade,
			const int executingGrade,
			bool formSigned = false);

		const std::string getName() const;
		bool isSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;

		void	beSigned(Bureaucrat& instance);

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

};


std::ostream& operator<<(std::ostream& output, const Form& instance);
