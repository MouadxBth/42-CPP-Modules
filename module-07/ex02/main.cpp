/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:32:38 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 20:06:35 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), length(0) {}

template <typename T>
Array<T>::Array(size_t length) : elements(new T[length]), length(length)
{
    for (size_t index = 0; index < length; ++index)
        elements[index] = T();
}

template <typename T>
Array<T>::Array(const Array& instance) : elements(new T[instance.length]), length(instance.length)
{
    for (size_t index = 0; index < length; ++index)
        elements[index] = instance.elements[index];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] elements;
       
        length = other.length;
        elements = new T[length];
       
        for (size_t i = 0; i < length; ++i)
            elements[i] = other.elements[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] elements;
}

template <typename T>
T& Array<T>::operator[](size_t index) throw(std::exception)
{
    if (index >= length)
        throw std::exception();
    return elements[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return length;
}

int main() {
    // Testing the Array class template
    Array<int> arr1(5);  // Create an array of 5 ints
    for (size_t i = 0; i < arr1.size(); ++i)
        arr1[i] = i + 1;

    Array<int> arr2(arr1);  // Create a copy of arr1

    std::cout << "arr1: ";
    for (size_t i = 0; i < arr1.size(); ++i)
        std::cout << arr1[i] << " ";
    
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (size_t i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    
    std::cout << std::endl;

    arr1[2] = 100;  // Modify arr1, arr2 should remain unaffected

    std::cout << "After modifying arr1: " << std::endl;
    std::cout << "arr1: ";
    for (size_t i = 0; i < arr1.size(); ++i)
        std::cout << arr1[i] << " ";
    
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (size_t i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    
    std::cout << std::endl;

    // Accessing out-of-bounds index
    try {
        int value = arr1[10];  // Index 10 is out of bounds
        std::cout << "Value at index 10: " << value << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: Out-of-bounds access" << std::endl;
    }

    return 0;
}
