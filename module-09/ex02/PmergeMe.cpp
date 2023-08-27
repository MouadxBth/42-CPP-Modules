/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:50:30 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/27 04:08:36 by mbouthai         ###   ########.fr       */
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

static void parseNumbers(std::vector<int>& numbers, const std::string& input) {
    std::istringstream iss(input);
    std::string token;
    int value;

    while (iss >> token) {
        bool valid = true;
        bool hasSign = false;

        for (size_t i = 0; i < token.size(); ++i) {
            if (i == 0 && (token[i] == '+' || token[i] == '-')) {
                hasSign = true;
                continue;
            }
            if (!std::isdigit(token[i])) {
                valid = false;
                break;
            }
            if (hasSign)
                hasSign = false;
        }

        if (!valid || hasSign) {
            std::cerr << "Error: Invalid argument '"
                << token
                << "'. Only positive integers are allowed."
                << std::endl;
            std::exit(EXIT_FAILURE);
        }
        value = std::atoi(token.c_str());
        if (value < 0)
        {
            std::cerr << "Error: Invalid argument '"
                << token
                << "'. Only positive integers are allowed."
                << std::endl;
            std::exit(EXIT_FAILURE);
        }
        numbers.push_back(value);
    }
}

static void    checkArgument(std::string& arg)
{
    for (size_t index = 0; index < arg.size(); index++)
    {
        if (!std::isspace(arg[index]) 
            && arg[index] != '+'
            && !std::isdigit(arg[index]))
        {
            std::cerr << "Error: Invalid argument '"
                    << arg
                    << "'. Only positive integers are allowed."
                    << std::endl;
                std::exit(EXIT_FAILURE);
        }
    }
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    std::string currentArgument;

    for (int index = 1; index < argc; index++)
    {
        currentArgument = argv[index];
        if (currentArgument.empty())
            continue;
        checkArgument(currentArgument);
        parseNumbers(_sequence, currentArgument);
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
    std::cout << message 
        << (end.tv_sec * 1e6 + end.tv_usec) - (start.tv_sec * 1e6 + start.tv_usec) 
        << " us" 
        << std::endl;
}

std::string PmergeMe::intToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void    PmergeMe::execute()
{
    if (_sequence.empty())
        return ;
    std::vector<int> copy(_sequence);

    displaySequence("Before: ", _sequence);

    timeval start_tree = time();
    sort(_sequence, false);
    timeval end_tree = time();

    timeval start_minimum_heap = time();
    sort(copy, true);
    timeval end_minimum_heap = time();

    displaySequence("After: ", _sequence);

    displayTime("Time to process a range of "
        + intToString(_sequence.size())
        + " elements with std::priority_queue ", start_tree, end_tree);

    displayTime("Time to process a range of "
        + intToString(copy.size())
        + " elements with std::multiset ", start_minimum_heap, end_minimum_heap);
}
