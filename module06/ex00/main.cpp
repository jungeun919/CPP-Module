/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:49:29 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/09 08:32:41 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid argument" << std::endl;
		return 1;
	}
	Converter::convert(argv[1]);

	std::cout << std::endl;
	// std::string	input = argv[1];
	// std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
	// // std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
	// std::cout << "int: " << static_cast<int>(static_cast<double>(input[0])) << std::endl;
	// std::cout << "float: " << static_cast<float>(input[0]) << std::endl;
	// std::cout << "double: " << static_cast<double>(input[0]) << std::endl;

	std::string input = argv[1];
	std::cout << "char: " << (char)input[0] << std::endl;
	std::cout << "int: " << (int)input[0] << std::endl;
	std::cout << "float: " << (float)input[0] << std::endl;
	std::cout << "double: " << (double)input[0] << std::endl;
	
	return 0;
}
