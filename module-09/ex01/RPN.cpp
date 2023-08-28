/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:13:11 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/28 02:51:17 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& instance)
{
    (void) instance;
}

RPN& RPN::operator=(const RPN& instance)
{
    (void) instance;
    return (*this);
}

std::stack<int> RPN::getOperands() const
{
    return (_operands);
}

bool    RPN::isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int     RPN::performOperation(const std::string& operation, int first, int second) throw(std::runtime_error)
{
    if (operation == "+") return first + second;
    if (operation == "-") return first - second;
    if (operation == "*") return first * second;
    if (operation == "/")
    {
        if (!second)
            throw (std::runtime_error("Error! cannot divide by 0."));
        return first / second;
    }
    return 0; // This should not happen if input is valid
}

bool RPN::isNumber(const std::string& token)
{
    for (size_t index = 0; index < token.size(); index++)
    {
        if (!isdigit(token[index]))
            return (false);
    }
    return (true);
}

void    RPN::evaluate(const std::string& expression)
{
    if (expression.empty())
        return ;
    
    std::stringstream ss(expression);
    std::string token;


    while (ss >> token)
    {
        if (!isNumber(token) 
            && !std::isspace(token[0])
            && token[0] != '*'
            && token[0] != '/'
            && token[0] != '-'
            && token[0] != '+')
        {
            std::cout << "Error: Invalid arguments!" << std::endl;
            return ;
        }
        if (std::isdigit(token[0]))
        {
            int value = atoi(token.c_str());
            if (value < 0 || value > 9)
            {
                std::cout << "Error: Invalid arguments!" << std::endl;
                return ;
            }
            _operands.push(value);
        }
        else if (isOperator(token))
        {
            if (_operands.size() < 2)
            {
                std::cout << "Error: Insufficient operands for operation: " << token << std::endl;
                return ;
            }
            
            int second = _operands.top();
            _operands.pop();
            
            int first = _operands.top();
            _operands.pop();
           
            try
            {
                int result = performOperation(token, first, second);
                _operands.push(result);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
                return ;
            }
            
        }
        else
        {
            std::cout << "Error: Invalid token: " << token << std::endl;
            return ;
        }
    }

    if (_operands.size() != 1)
    {
        std::cout << "Error: Insufficient operators or too many operands in the expression." << std::endl;
        return ;
    }
    std::cout << _operands.top() << std::endl;
}