/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 03:49:29 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/12 15:08:41 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid argument" << std::endl;
		return 1;
	}
	
	ScalarConverter::convert(argv[1]);
	
	std::cout << std::endl;
	// char value = 'a';
	int value = 11111111;
	// float value = nanf;
	// double value = nan;

    char c = static_cast<char>(value);
	int n = static_cast<int>(value);
    float f = static_cast<float>(value);
    double d = static_cast<double>(value);

    std::cout << "char: " << c << std::endl;
	std::cout << "int: " << n << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;

	return 0;
}
