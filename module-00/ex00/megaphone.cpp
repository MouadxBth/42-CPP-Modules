/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:53:54 by mbouthai          #+#    #+#             */
/*   Updated: 2023/04/11 16:08:28 by mbouthai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void
shout(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++)
			std::cout << (char)(std::toupper(argv[i][j]));
	}
	std::cout << std::endl;
}


int
main(int argc, char **argv)
{
	if (argc > 1) 
		return (shout(argc, argv), 0);
	return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE. *" << std::endl, 0);
}
