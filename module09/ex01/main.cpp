/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:26 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 01:28:26 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw RPN::ErrorException();
		
		RPN::run(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
