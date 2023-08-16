/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:25:10 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 19:06:14 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Data.h"
# include <stdint.h>

class Serializer
{

public:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& instance);
    Serializer  &operator=(const Serializer& instance);

    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};