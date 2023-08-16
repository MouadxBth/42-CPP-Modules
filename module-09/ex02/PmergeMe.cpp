/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:50:30 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 05:47:46 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <cstring>
#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& instance)
{
    (void) instance;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& instance)
{
    if (this != &instance)
    {
        _sequence_deque.clear();
        _sequence_vector.clear();

        std::copy(instance._sequence_vector.begin(),
            instance._sequence_vector.end(),
            std::back_inserter(_sequence_vector));

        std::copy(instance._sequence_deque.begin(),
            instance._sequence_deque.end(),
            std::back_inserter(_sequence_deque));
    }
    return (*this);
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    for (int index = 1; index < argc; index++)
    {
        if (strcmp(argv[index], " ") == 0)
            continue;
        
        int j = -1;
        while (argv[index][++j])
        {
            if (!isdigit(argv[index][j]))
            {
                std::cerr << "Error: Invalid argument '" 
                    << argv[index] 
                    << "'. Only positive integers are allowed." 
                    << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }
    }
    for (int index = 1; index < argc; ++index) {
        int number = std::atoi(argv[index]);
        if (number <= 0) {
            std::cerr << "Error: Invalid argument '" 
                << argv[index] 
                << "'. Only positive integers are allowed." 
                << std::endl;
            std::exit(EXIT_FAILURE);
        }
        _sequence_vector.push_back(number);
        _sequence_deque.push_back(number);
    }
}

void    PmergeMe::execute()
{
    displaySequenceVector("Before: ", _sequence_vector);

    clock_t start_vector = clock();
    mergeInsertSortVector(_sequence_vector, 0, _sequence_vector.size() - 1);
    clock_t end_vector = clock();

    clock_t start_deque = clock();
    mergeInsertSortDeque(_sequence_deque, 0, _sequence_deque.size() - 1);
    clock_t end_deque = clock();

    displaySequenceVector("After: ", _sequence_vector);
    
    displayTime("Time to process a range of " 
        + intToString(_sequence_vector.size()) 
        + " elements with std::vector: ", start_vector, end_vector);
    
    displayTime("Time to process a range of " 
        + intToString(_sequence_deque.size())
        + " elements with std::deque: ", start_deque, end_deque);
}

void PmergeMe::displaySequenceVector(const std::string& message, const std::vector<int>& sequence)
{
    std::cout << message;
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::displayTime(const std::string& message, clock_t start, clock_t end)
{
    double duration = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;
    std::cout << message << duration << " us" << std::endl;
}

std::string PmergeMe::intToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void PmergeMe::insertSortVector(std::vector<int>& sequence, int left, int right)
{
    for (int index = left, secondIndex = index + 1, currentValue = sequence[secondIndex];
        index < right;
        index++, secondIndex = index + 1, currentValue = sequence[secondIndex]) {

        while (secondIndex > left && sequence[secondIndex - 1] > currentValue) {
            sequence[secondIndex] = sequence[secondIndex - 1];
            secondIndex--;
        }
        sequence[secondIndex] = currentValue;
    }
}

void PmergeMe::mergeVector(std::vector<int>& sequence, int left, int middle, int right)
{
    int leftVectorStart = middle - left + 1;
    int rightVectorStart = right - middle;

    std::vector<int> leftVector(sequence.begin() + left, sequence.begin() + middle + 1);
    std::vector<int> rightVector(sequence.begin() + middle + 1, sequence.begin() + right + 1);

    int index = 0, secondIndex = 0, current = left;
    
    while (index < leftVectorStart && secondIndex < rightVectorStart)
        sequence[current++] = (leftVector[index] <= rightVector[secondIndex]) ?
            leftVector[index++] : rightVector[secondIndex++];

    while (index < leftVectorStart)
        sequence[current++] = leftVector[index++];

    while (secondIndex < rightVectorStart)
        sequence[current++] = rightVector[secondIndex++];
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& sequence, int left, int right)
{
    if (right - left > 20)
    {
        int middle = left + (right - left) / 2;

        mergeInsertSortVector(sequence, left, middle);
        mergeInsertSortVector(sequence, middle + 1, right);

        mergeVector(sequence, left, middle, right);
    }
    else
    {
        insertSortVector(sequence, left, right);
    }
}

void PmergeMe::insertSortDeque(std::deque<int>& sequence, int left, int right) {
    for (int index = left, secondIndex = index + 1, currentValue = sequence[secondIndex];
        index < right;
        index++, secondIndex = index + 1, currentValue = sequence[secondIndex]) {

        while (secondIndex > left && sequence[secondIndex - 1] > currentValue) {
            sequence[secondIndex] = sequence[secondIndex - 1];
            secondIndex--;
        }
        sequence[secondIndex] = currentValue;
    }
}

void PmergeMe::mergeDeque(std::deque<int>& sequence, int left, int middle, int right) {
    int leftDequeStart = middle - left + 1;
    int rightDequeStart = right - middle;

    std::deque<int> leftVector(sequence.begin() + left, sequence.begin() + middle + 1);
    std::deque<int> rightVector(sequence.begin() + middle + 1, sequence.begin() + right + 1);

    int index = 0, secondIndex = 0, current = left;
    
    while (index < leftDequeStart && secondIndex < rightDequeStart)
        sequence[current++] = (leftVector[index] <= rightVector[secondIndex]) ?
            leftVector[index++] : rightVector[secondIndex++];

    while (index < leftDequeStart)
        sequence[current++] = leftVector[index++];

    while (secondIndex < rightDequeStart)
        sequence[current++] = rightVector[secondIndex++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& sequence, int left, int right)
{
    if (right - left > 20)
    {
        int middle = left + (right - left) / 2;

        mergeInsertSortDeque(sequence, left, middle);
        mergeInsertSortDeque(sequence, middle + 1, right);

        mergeDeque(sequence, left, middle, right);
    }
    else
    {
        insertSortDeque(sequence, left, right);
    }
}
