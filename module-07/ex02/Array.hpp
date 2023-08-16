/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 14:29:25 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/07 19:54:51 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class Array 
{
    private:
        T* elements;
        size_t length;

    public:
        Array();
        ~Array();
        Array(const Array& other);
        Array& operator=(const Array& other);

        explicit Array(size_t n);

        T& operator[](size_t index) throw(std::exception);

        size_t size() const;
};