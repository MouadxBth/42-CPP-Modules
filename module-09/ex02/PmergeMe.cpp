/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:50:30 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/25 18:02:34 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <set>
#include <queue>
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
        _sequence.clear();

        std::copy(instance._sequence.begin(),
            instance._sequence.end(),
            std::back_inserter(_sequence));
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
                    << " "
                    << argv[index][j]
                    << "'. 1 Only positive integers are allowed." 
                    << std::endl;
                std::exit(EXIT_FAILURE);
            }
        }
    }
    for (int index = 1; index < argc; ++index) {
        int number = std::atoi(argv[index]);
        if (number < 0) {
            std::cerr << "Error: Invalid argument '" 
                << argv[index] 
                << "'. Only positive integers are allowed." 
                << std::endl;
            std::exit(EXIT_FAILURE);
        }
        _sequence.push_back(number);
    }
}

void PmergeMe::displaySequence(const std::string& message, const std::vector<int>& sequence)
{
    std::cout << message;
    for (size_t index = 0; index < sequence.size(); ++index) {
        std::cout << sequence[index] << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::sort(std::vector<int>& sequence, bool multiset)
{
    if (sequence.size() < 2)
        return ;
    
    typedef typename std::multiset< std::pair<int, int> > integerPairMultiset;
    typedef typename integerPairMultiset::iterator integerPairMultisetIterator;

    typedef typename std::priority_queue< std::pair<int, int>,
        std::vector< std::pair<int, int> >,
        std::greater< std::pair<int, int> > > integerAscendingPriorityQueue;
    
    std::vector< std::pair<int, int> > pairs;

    for (size_t index = 0; index + 1 < sequence.size(); index += 2)
    {
        pairs.push_back(std::make_pair(
            std::max(sequence[index], sequence[index + 1]),
            std::min(sequence[index], sequence[index + 1])
        ));
    }

    if (multiset)
    {
        integerPairMultiset redBlackTree(pairs.begin(), pairs.end());
        
        pairs.clear();

        for (integerPairMultisetIterator it = redBlackTree.begin(); it != redBlackTree.end(); it++)
            pairs.push_back(*it);
    }
    else
    {
         integerAscendingPriorityQueue minimumHeap(pairs.begin(), pairs.end());

         pairs.clear();

         while (!minimumHeap.empty())
         {
            pairs.push_back(minimumHeap.top());
            minimumHeap.pop();
         } 
    }

    std::vector<int> result, pend;

    result.push_back(pairs[0].second);

    for (std::vector< std::pair<int, int> >::iterator it = pairs.begin();
        it != pairs.end();
        it++)
    {
        result.push_back(it->first);
        pend.push_back(it->second);
    }

    if (sequence.size() % 2)
        pend.push_back(sequence[sequence.size() - 1]);

     for (size_t index = 1; index < pend.size(); index++) {
        std::vector<int>::iterator position = std::upper_bound(result.begin(), result.end(), pend[index]);
        result.insert(position, pend[index]);
    }

    for (size_t index = 0; index < result.size(); index++)
        sequence[index] = result[index];
    
}

timeval PmergeMe::time()
{
    timeval	now;
	gettimeofday(&now, NULL);
    return (now);
}

void PmergeMe::displayTime(const std::string& message, timeval start, timeval end)
{
    unsigned long long duration = (end.tv_sec * 1e6 + end.tv_usec) - (start.tv_sec * 1e6 + start.tv_usec);
    std::cout << message << duration << " us" << std::endl;
}

std::string PmergeMe::intToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void    PmergeMe::execute()
{
    std::vector<int> copy(_sequence);

    displaySequence("Before: ", _sequence);

    timeval start_tree = time();
    sort(_sequence, false);
    timeval end_tree = time();

    displaySequence("Before: ", copy);

    timeval start_minimum_heap = time();
    sort(copy, true);
    timeval end_minimum_heap = time();

    displaySequence("After: ", _sequence);

    displaySequence("After: ", copy);
    
    displayTime("Time to process a range of " 
        + intToString(_sequence.size()) 
        + " elements with std::vector: ", start_tree, end_tree);
    
    displayTime("Time to process a range of " 
        + intToString(copy.size())
        + " elements with std::deque: ", start_minimum_heap, end_minimum_heap);
}
