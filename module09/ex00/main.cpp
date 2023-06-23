/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:11 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 01:28:12 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <typeinfo>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw BitcoinExchange::CouldNotOpenFileException();

		BitcoinExchange	db;
		std::string		line;

		std::ifstream	csv("data.csv");
		if (!csv.is_open())
			throw BitcoinExchange::CouldNotOpenCSVException();

		std::getline(csv, line);
		while (std::getline(csv, line))
		{
			std::string key = line.substr(0, line.find(','));
			std::string value = line.substr(line.find(',') + 1);
			db.insert(key, std::strtod(value.c_str(), NULL));
		}

		std::ifstream inputFile(argv[1]);
		if (!inputFile.is_open())
			throw BitcoinExchange::CouldNotOpenFileException();
		
		std::getline(inputFile, line);
		while (std::getline(inputFile, line))
		{
			std::string key = line.substr(0, line.find('|'));
			std::string value = line.substr(line.find('|') + 1);
			try
			{
				float converted = db.convert(key, std::strtod(value.c_str(), NULL));
				std::cout << key << "=>" << value << " = " << converted << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << e.what();
				if (typeid(e) == typeid(BitcoinExchange::BadInputException))
					std::cout << " => " << key;
				std::cout << std::endl;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
