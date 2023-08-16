/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:09:54 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/14 01:22:45 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stack>
# include <string>

class RPN
{

private:
    std::stack<int> _operands;
    bool isOperator(const std::string& token);
    int performOperation(const std::string& operation, int first, int second);

public:
    RPN();
    ~RPN();
    RPN(const RPN& instance);
    RPN& operator=(const RPN& instance);

    std::stack<int> getOperands() const;

    int evaluate(const std::string& expression);

};