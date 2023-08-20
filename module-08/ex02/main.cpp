/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 05:58:54 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/19 16:06:27 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        std::stack<int> s(mstack);
    }
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(10);
        mstack.push(15);

        std::cout << "Using iterators:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;

        std::cout << "Top element: " 
            << mstack.top() 
            << std::endl;
       
        mstack.pop();
        
        std::cout << "After pop, top element: " 
            << mstack.top() 
            << std::endl;

        std::cout << "Size of stack: " 
            << mstack.size() 
            << std::endl;

        mstack.push(20);
        mstack.push(25);
        mstack.pop();

        std::cout << std::endl;
    }
    {
        std::cout << "Using std::list:" << std::endl;
        
        std::list<int> myList;
        
        myList.push_back(1);
        myList.push_back(2);
        myList.push_back(3);

        for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
            std::cout << *it << " ";
        
        std::cout << std::endl;

        std::cout << "Using MutantStack:" << std::endl;
       
        MutantStack<int> mstack;
       
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);

        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;
    }
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);

        std::cout << "Using regular iterators:" << std::endl;
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Using reverse iterators:" << std::endl;
        for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Using const iterators:" << std::endl;
        for (MutantStack<int>::const_iterator it = mstack.cbegin(); it != mstack.cend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Using const reverse iterators:" << std::endl;
        for (MutantStack<int>::const_reverse_iterator it = mstack.crbegin(); it != mstack.crend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
	return 0;
}