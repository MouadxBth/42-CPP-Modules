/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:22:28 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/04 16:18:54 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <string>
# include <iostream>

class Bureaucrat;

class AForm
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
		
		AForm();
		virtual ~AForm();
		AForm(const AForm& instance);
		AForm& operator=(const AForm& instance);

		AForm(const std::string name,
			const int signingGrade,
			const int executingGrade,
			bool formSigned = false);

		const std::string getName() const;
		bool isSigned() const;
		int getSigningGrade() const;
		int getExecutingGrade() const;

		void	beSigned(Bureaucrat& instance) throw(GradeTooHighException, GradeTooLowException);

		void	execute(const Bureaucrat &instance) const throw(GradeTooLowException, std::runtime_error);

		virtual void	executeForm() const throw(std::runtime_error) = 0;
};


std::ostream& operator<<(std::ostream& output, const AForm& instance);
