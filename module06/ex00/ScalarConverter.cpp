/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 01:25:35 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/12 15:08:09 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& object)
{
	*this = object;
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& object)
{
	(void)object;
	return *this;
}

int	ScalarConverter::checkType(std::string input)
{
	char	*ptr = NULL;
	std::strtod(input.c_str(), &ptr);

	if (input == "nanf" || input == "nan" || input == "+inff" || input == "-inff" || input == "+inf" || input == "-inf")
		return (0);
	else if (ptr[0] == '\0' || (std::string(ptr) == "f" && input.size() != 1))
		return (1);
	else if (input.size() == 1 && std::isprint(input[0]))
		return (2);
	else
		return (3);
}

void	ScalarConverter::convert(std::string input)
{
	double	value;
	char	*ptr = NULL;
	int		type;
	
	value = std::strtod(input.c_str(), &ptr);
		
	type = checkType(input);
	
	if (type == 3) // ab, "qw er", "12 34"
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	
	else if (type == 0) // nanf, inff, inf
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		
		if (input == "nanf" || input == "nan")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (input == "+inff" || input == "+inf")
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else if (input == "-inff" || input == "-inf")
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
	}

	else if (type == 2) // a, A
	{
		std::cout << "char: " << input[0] << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
		std::cout << "double: " << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
	}

	else if (type == 1) // 123.45f, 1, 23
	{
		std::cout << "char: ";
		if (value > 31 && value < 127)
			std::cout << static_cast<char>(value) << std::endl;
		else if ((value >= 0 && value < 32) || (value >= 127 && value < 128))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "impossible" << std::endl;
		
		std::cout << "int: ";
		if (value < 2147483648 && value > -2147483649)
			std::cout << static_cast<int>(value) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		
		std::cout << "float: ";
		if (static_cast<float>(value) == static_cast<int>(static_cast<float>(value)))
			std::cout << static_cast<float>(value) << ".0f" << std::endl;
		else
		 	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << static_cast<float>(value) << "f" << std::endl;
		
		std::cout <<"double: ";
		if (value == static_cast<int>(value))
			std::cout << value << ".0" << std::endl;
		else
		 	std::cout << std::setprecision(std::numeric_limits<float>::digits10) << value << std::endl;
	}
}
