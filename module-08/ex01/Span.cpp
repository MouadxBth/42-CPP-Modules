/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 04:53:18 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/08 05:53:22 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>

Span::Span() : maxSize(0), numbers() {}

Span::~Span() {}

Span::Span(const Span& instance)
{
    *this = instance;
}

Span& Span::operator=(const Span& instance)
{
    if (this != &instance)
    {
        this->maxSize = instance.maxSize;
        this->numbers.clear();
        for (unsigned int index = 0; index < maxSize; index++)
            this->numbers[index] = instance.numbers[index];
    }
    return (*this);
}

Span::Span(unsigned int maxSize) : maxSize(maxSize), numbers() {}

void    Span::addNumber(int number) throw(std::runtime_error)
{
    if (numbers.size() >= maxSize)
        throw (std::runtime_error("Span is full!"));
    
    numbers.push_back(number);
}

int     Span::shortestSpan() throw(std::runtime_error)
{
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to calculate span.");
    }

    std::sort(numbers.begin(), numbers.end());
    
    int shortest = std::numeric_limits<int>::max();
    int difference = shortest;
    
    for (size_t index = 1; index < numbers.size(); ++index)
    {
        difference = numbers[index] - numbers[index - 1];
        if (difference < shortest)
            shortest = difference;
    }
    return shortest;
}

int     Span::longestSpan() throw(std::runtime_error)
{
    if (numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to calculate span.");

    return (*std::max_element(numbers.begin(), numbers.end())) 
        - (*std::min_element(numbers.begin(), numbers.end()));
}

void    Span::addNumbers(std::vector<int>::iterator start, std::vector<int>::iterator end) throw(std::runtime_error)
{
    if (numbers.size() + (end - start) > this->maxSize)
    {
        throw std::runtime_error("Adding numbers exceeds the Span size.");
    }
	
    while (start != end)
		this->addNumber(*(start++));
}

std::vector<int>& Span::getNumbers()
{
    return (this->numbers);
}

std::ostream& operator<<(std::ostream& stream, Span& instance)
{
    for (size_t index = 0; index < instance.getNumbers().size(); index++)
        stream << instance.getNumbers()[index] << " ";
    
    return (stream);
}