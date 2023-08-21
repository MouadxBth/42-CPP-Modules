/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:32:38 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/21 10:21:00 by mbouthai         ###   ########.fr       */
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
        throw std::exception("Array index out of bounds");
    else if (!elements)
        throw std::exception("Array is empty!");
    return elements[index];
}

template <typename T>
size_t Array<T>::size() const
{
    return length;
}

int main() {
    Array<int> first(5);

    for (size_t index = 0; index < first.size(); ++index)
        first[index] = index + 1;

    Array<int> copy(first);

    std::cout << "first: ";
    for (size_t index = 0; index < first.size(); ++index)
        std::cout << first[index] << " ";
    
    std::cout << std::endl;

    std::cout << "copy: ";
    for (size_t index = 0; index < copy.size(); ++index)
        std::cout << copy[index] << " ";
    
    std::cout << std::endl;

    first[2] = 100;  // 

    std::cout << "Modify first, copy should remain unaffected\n" 
        << "After modifying first: \n"
        << "first: " 
        << std::endl;

    for (size_t index = 0; index < first.size(); ++index)
        std::cout << first[index] << " ";
    
    std::cout << std::endl;

    std::cout << "copy: ";
    for (size_t index = 0; index < copy.size(); ++index)
        std::cout << copy[index] << " ";
    
    std::cout << std::endl;

    try {
        int value = first[10];  
        std::cout << "Value at index 10: " << value << std::endl;
    } catch (const std::exception& ex) {
        std::cout << "Exception caught: Out-of-bounds access" << std::endl;
    }

    return 0;
}
