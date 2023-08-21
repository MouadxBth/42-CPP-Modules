/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:46:45 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/21 12:41:54 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
    int random_num = rand() % 3;
    
    switch (random_num) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return (NULL);
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cerr << "Unknown element!" << std::endl;
    }
}

void identify(Base& p) {
    Base base;

    try
    {
        base = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        base = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {}

    try
    {
        base = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Unknown element!" << std::endl;
    }
    
    identify(&p);
}

int main() {
    std::srand(std::time(NULL));

    Base* instance = generate();

    std::cout << "Pointer identification: (known element)" << std::endl;
    identify(instance);

    std::cout << "Reference identification: (known element)" << std::endl;
    identify(*instance);

    std::cout << "Pointer identification: (unknown element)" << std::endl;
    identify(NULL);

    std::cout << "Reference identification: (unknown element)" << std::endl;
    identify(NULL);

    delete instance;

    return 0;
}
