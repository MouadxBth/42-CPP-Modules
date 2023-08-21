/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:13:32 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/21 10:12:23 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template <typename T, typename Function>
void iter(T* array, unsigned int length, Function function)
{
    for (unsigned int index = 0; index < length; index++)
        function(array[index]);
}

template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

int main() {
    {
        int intArray[] = {1, 2, 3, 4, 5};
        unsigned int intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

        std::cout << "Printing Integer Array elements: ";
        iter(intArray, intArrayLength, printElement<int>);
        std::cout << std::endl;
    }

    {
        double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
        unsigned int doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

        std::cout << "Printing Double Array elements: ";
        iter(doubleArray, doubleArrayLength, printElement<double>);
        std::cout << std::endl;
    }

    {
        std::string stringArray[] = {"Hello", "World", "How", "Is", "It", "Going?"};

        std::cout << "Printing String Array elements: ";
        iter(stringArray, 6, printElement<std::string>);
        std::cout << std::endl;
    }

    {
        int intArray[] = {1, 2, 3, 4, 5};

        std::cout << "Printing only 3 integers from the Integer Array elements: ";
        iter(intArray, 3, printElement<int>);
        std::cout << std::endl;
    }

    return 0;
}