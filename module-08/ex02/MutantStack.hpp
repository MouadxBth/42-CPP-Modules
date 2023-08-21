/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 05:57:58 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/21 10:32:25 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Iterator functions
    iterator begin();
    iterator end();

    // Reverse iterators
    reverse_iterator rbegin();
    reverse_iterator rend();

    // Const iterators
    const_iterator cbegin() const;
    const_iterator cend() const;

    // Const reverse iterators
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
};