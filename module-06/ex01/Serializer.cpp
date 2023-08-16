/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:29:03 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 19:07:16 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

Serializer::Serializer(const Serializer& instance)
{
    (void) instance;
}

Serializer  &Serializer::operator=(const Serializer& instance)
{
    (void) instance;
    return (*this);
}


uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<unsigned long>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
