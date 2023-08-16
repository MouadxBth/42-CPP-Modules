/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 01:46:15 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 04:09:38 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>

class PmergeMe
{

private:
    std::vector<int>    _sequence_vector;
    std::deque<int>     _sequence_deque;
    
    void    displaySequenceVector(const std::string& message, const std::vector<int>& sequence);
    void    displaySequenceDeque(const std::string& message, const std::deque<int>& sequence);
    void    displayTime(const std::string& message, clock_t start, clock_t end);
    std::string     intToString(int num);

    void    insertSortVector(std::vector<int>& sequence, int left, int right);
    void    mergeVector(std::vector<int>& sequence, int left, int middle, int right);
    void    mergeInsertSortVector(std::vector<int>& sequence, int left, int right);

    void    insertSortDeque(std::deque<int>& sequence, int left, int right);
    void    mergeDeque(std::deque<int>& sequence, int left, int middle, int right);
    void    mergeInsertSortDeque(std::deque<int>& sequence, int left, int right);

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe& instance);
    PmergeMe& operator=(const PmergeMe& instace);

    PmergeMe(int argc, char **argv);
    
    void    execute();

};