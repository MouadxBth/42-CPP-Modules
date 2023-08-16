/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 04:04:54 by mbouthai          #+#    #+#             */
/*   Updated: 2023/08/16 04:05:35 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        std::cerr << "Error: No arguments provided." << std::endl;
        return 1;
    }

    PmergeMe instance(argc, argv);

    instance.execute();

    return 0;
}
