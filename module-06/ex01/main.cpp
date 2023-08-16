/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:32:27 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 19:11:55 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.h"
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data obj = {.id = 'A', .age = 21, .price = .1337f};

    // Serialize the address of the Data object
    uintptr_t serializedPtr = Serializer::serialize(&obj);

    // Deserialize the pointer
    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    // Check if the deserialized pointer is equal to the original pointer
    if (deserializedPtr == &obj) {
        std::cout << "Serialization and deserialization successful! Pointers match.\n";
        std::cout << "Id: " << deserializedPtr->id << "\n";
        std::cout << "Age: " << deserializedPtr->age << "\n";
        std::cout << "Price: " << deserializedPtr->price << "\n";
    } else {
        std::cout << "Serialization and deserialization failed! Pointers do not match.\n";
    }

    return 0;
}
