/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:09:54 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/28 02:46:26 by mbouthai         ###   ########.fr       */
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
    bool isNumber(const std::string& token);
    int performOperation(const std::string& operation, int first, int second) throw(std::runtime_error);

public:
    RPN();
    ~RPN();
    RPN(const RPN& instance);
    RPN& operator=(const RPN& instance);

    std::stack<int> getOperands() const;

    void evaluate(const std::string& expression);

};