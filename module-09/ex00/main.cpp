/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 01:27:25 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 05:59:28 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: not enough arguments!\n"
            << "./btc <{file}.csv>"
            << std::endl;
        return (1); 
    }
	BitcoinExchange exchange;

    exchange.calculate(argv[1]);
	return (0);
}