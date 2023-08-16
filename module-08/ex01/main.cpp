/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 05:14:10 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/08 05:49:20 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    {    
        Span sp = Span(5);
       
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {    
        Span sp = Span(5);
       
        sp.addNumber(-1);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        
        try {
            std::cout << "Shortest span: " 
                << sp.shortestSpan() 
                << std::endl;

            std::cout << "Longest span: " 
                << sp.longestSpan() 
                << std::endl;
        } catch (const std::exception& e)
        {
            std::cerr << "Error: " 
                << e.what() 
                << std::endl;
        }
    }
    {
        const unsigned int maxSize = 10000; 
        Span sp(maxSize);

        for (unsigned int i = 0; i < maxSize; ++i) {
            try {
                sp.addNumber(std::rand());
            } catch (const std::exception& e)
            {
                std::cerr << "Error: " 
                    << e.what() 
                    << std::endl;
            }
        }

        try {
            std::cout << "Shortest span: " 
                << sp.shortestSpan() 
                << std::endl;

            std::cout << "Longest span: " 
                << sp.longestSpan() 
                << std::endl;

            //std::cout << sp << std::endl;
        } catch (const std::exception& e)
        {
            std::cerr << "Error: " 
                << e.what() 
                << std::endl;
        }
    }
    {
        const unsigned int maxSize = 10000; 
        Span sp(maxSize);
        std::vector<int> numbers;
        
        for (unsigned int i = 0; i < maxSize; ++i) {
            try {
                numbers.push_back(std::rand());
            } catch (const std::exception& e)
            {
                std::cerr << "Error: " 
                    << e.what() 
                    << std::endl;
            }
        }

        try {
            sp.addNumbers(numbers.begin(), numbers.end());
            
            std::cout << "Shortest span: " 
                << sp.shortestSpan() 
                << std::endl;

            std::cout << "Longest span: " 
                << sp.longestSpan() 
                << std::endl;

        } catch (const std::exception& e)
        {
            std::cerr << "Error: " 
                << e.what() 
                << std::endl;
        }
    }
    {
        const unsigned int maxSize = 1000000; 
        Span sp(maxSize);
        std::vector<int> numbers;
        
        for (unsigned int i = 0; i < maxSize; ++i) {
            try {
                numbers.push_back(std::rand());
            } catch (const std::exception& e)
            {
                std::cerr << "Error: " 
                    << e.what() 
                    << std::endl;
            }
        }

        try {
            sp.addNumbers(numbers.begin(), numbers.end());
            
            std::cout << "Shortest span: " 
                << sp.shortestSpan() 
                << std::endl;

            std::cout << "Longest span: " 
                << sp.longestSpan() 
                << std::endl;

        } catch (const std::exception& e)
        {
            std::cerr << "Error: " 
                << e.what() 
                << std::endl;
        }
    }
    {
        const unsigned int maxSize = 5; 
        Span sp(maxSize - 1);
        std::vector<int> numbers;
        
        for (unsigned int i = 0; i < maxSize; ++i) {
            try {
                numbers.push_back(std::rand());
            } catch (const std::exception& e)
            {
                std::cerr << "Error: " 
                    << e.what() 
                    << std::endl;
            }
        }

        try {
            sp.addNumbers(numbers.begin(), numbers.end());
            
            std::cout << "Shortest span: " 
                << sp.shortestSpan() 
                << std::endl;

            std::cout << "Longest span: " 
                << sp.longestSpan() 
                << std::endl;

        } catch (const std::exception& e)
        {
            std::cerr << "Error: " 
                << e.what() 
                << std::endl;
        }
    }

    return 0;
}