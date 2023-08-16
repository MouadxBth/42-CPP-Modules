/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:13:32 by mbouthai          #+#    #+#             */
/*   Updated: 2023/07/18 14:28:25 by mbouthai         ###   ########.fr       */
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
    int intArray[] = {1, 2, 3, 4, 5};
    unsigned int intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Printing intArray elements: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    unsigned int doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Printing doubleArray elements: ";
    iter(doubleArray, doubleArrayLength, printElement<double>);
    std::cout << std::endl;

    return 0;
}