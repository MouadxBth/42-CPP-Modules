/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:49:07 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/01 11:57:47 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Bureaucrat.hpp"
# include <string>

class Form
{
    private:
        const std::string name;
        bool form_signed;
        const int signingGrade;
        const int executingGrade;
    
    public:
        Form();
        ~Form();
        Form(const Form& instance);
        Form& operator=(const Form& instance);

        Form(const std::string name, const int signingGrade, const int executingGrade);

        int getSigningGrade() const;
        int getExecutingGrade() const;

        const std::string getName() const;
        bool isSigned() const;

        void    beSigned(Bureaucrat& instance);

        
}