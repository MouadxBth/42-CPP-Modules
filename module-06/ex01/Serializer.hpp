/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:25:10 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/21 20:00:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Data.h"
# include <stdint.h>

class Serializer
{

private:
    Serializer();
    Serializer(const Serializer& instance);

public:
    ~Serializer();
    Serializer  &operator=(const Serializer& instance);

    static uintptr_t serialize(Data *ptr);
    static Data* deserialize(uintptr_t raw);
};