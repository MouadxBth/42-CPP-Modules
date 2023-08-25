/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:46:15 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/25 17:48:14 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <sys/time.h>
#include <queue>

class PmergeMe
{

private:
    std::vector<int>    _sequence;

    std::string     intToString(int num);

    timeval time();

    void    displayTime(const std::string& message, timeval start, timeval end);

    void    displaySequence(const std::string& message, const std::vector<int>& sequence);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& instance);
    PmergeMe& operator=(const PmergeMe& instace);

    PmergeMe(int argc, char **argv);
    
    void    sort(std::vector<int>& sequence, bool multiset);

    void    execute();

};