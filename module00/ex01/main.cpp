/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:37:23 by jungeun           #+#    #+#             */
/*   Updated: 2023/02/28 23:42:10 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{	
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{	
		std::cout << "Enter a command (ADD or SEARCH or EXIT): ";
		std::getline(std::cin, input);
		
		if (input.compare("ADD") == 0)
			phonebook.add();
		else if (input.compare("SEARCH") == 0)
			phonebook.search();
		else if (input.compare("EXIT") == 0 || std::cin.eof() == true)
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return 0;
}
