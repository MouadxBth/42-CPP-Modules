/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 01:25:50 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/14 01:26:51 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char** argv) {
    RPN rpn;

    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <RPN_expression>" << std::endl;
        return 1;
    }

    int result = rpn.evaluate(argv[1]);
    if (result != -1) {
        std::cout << result << std::endl;
    }

    return 0;
}





