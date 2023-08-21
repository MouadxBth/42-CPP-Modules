/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 20:20:14 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/21 10:27:39 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw (std::exception("Element was not found!"));
    }
    return it;
}

int main() {
    int values[] = {10, 20, 30, 40, 50};

    std::vector<int> vec(values, values + 5);

    try {
        int valueToFind = 30;
        std::vector<int>::iterator result = easyfind(vec, valueToFind);
       
        std::cout << "Value " << valueToFind;
        if (result == vec.end())
            std::cout << " not found." << std::endl;
        else
            std::cout << " found at index " << std::distance(vec.begin(), result) << std::endl;

        valueToFind = 60;
        result = easyfind(vec, valueToFind);
        
        std::cout << "Value " << valueToFind;
        if (result == vec.end()) {
            std::cout << " not found." << std::endl;
        } else {
            std::cout << " found at index " << std::distance(vec.begin(), result) << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}