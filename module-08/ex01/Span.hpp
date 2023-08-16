/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:47:29 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/08 05:48:03 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <vector>
# include <iostream>
# include <stdexcept>

class Span
{

private:
    unsigned int maxSize;
    std::vector<int> numbers;

public:
    Span();
    ~Span();
    Span(const Span& instance);
    Span& operator=(const Span& instance);

    Span(unsigned int maxSize);

    void    addNumber(int number) throw(std::runtime_error);

    int     shortestSpan() throw(std::runtime_error);
    int     longestSpan() throw(std::runtime_error);

    void    addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) throw(std::runtime_error);

    std::vector<int>& getNumbers();
};

std::ostream& operator<<(std::ostream& stream, Span& instance);