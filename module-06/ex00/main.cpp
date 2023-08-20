/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 01:55:06 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/19 18:11:37 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) 
        return (std::cout << "Usage: " << argv[0] << " <input_literal>" << std::endl, 1);

    std::string input(argv[1]);
    ScalarConverter::convert(input);

    return 0;
}