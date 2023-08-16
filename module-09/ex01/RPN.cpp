/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:13:11 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 05:37:53 by mbouthai         ###   ########.fr       */
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

int     RPN::performOperation(const std::string& operation, int first, int second)
{
    if (operation == "+") return first + second;
    if (operation == "-") return first - second;
    if (operation == "*") return first * second;
    if (operation == "/") return first / second;
    return 0; // This should not happen if input is valid
}

int    RPN::evaluate(const std::string& expression)
{
    if (expression.empty())
        return (-1);
    
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (isdigit(token[0]))
            _operands.push(atoi(token.c_str()));
        else if (isOperator(token))
        {
            if (_operands.size() < 2)
                return (std::cout << "Error: Insufficient operands for operation: " << token << std::endl, -1);
            
            int second = _operands.top();
            _operands.pop();
            
            int first = _operands.top();
            _operands.pop();
           
            int result = performOperation(token, first, second);
            _operands.push(result);
        }
        else
            return (std::cout << "Error: Invalid token: " << token << std::endl, -1);
    }

    if (_operands.size() != 1)
        return (std::cout << "Error: Insufficient operators or too many operands in the expression." << std::endl, -1);

    return (_operands.top());
}