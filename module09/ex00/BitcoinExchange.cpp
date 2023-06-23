/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:00 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 01:28:01 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& object)
{
	*this = object;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& object)
{
	if (this != &object)
		this->db = object.db;
	return *this;
}

void	BitcoinExchange::insert(std::string key, double value)
{
	this->db[key] = value;
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	int	idx = 0;
	int year, month, day;
	std::string	separator;

	std::istringstream ss(date);
	while (std::getline(ss, separator, '-'))
	{
		if (idx == 0)
			std::istringstream(separator) >> year;
		else if (idx == 1)
			std::istringstream(separator) >> month;
		else if (idx == 2)
			std::istringstream(separator) >> day;
		idx++;
	}
	if (idx != 3)
		return false;
	
	if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
			return false;
	}
	else if (month == 2)
	{
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			if (day > 29)
				return false;
		}
		else
		{
			if (day > 28)
				return false;
		}
	}
	return true;
}

double	BitcoinExchange::convert(std::string key, double value)
{
	if (isValidDate(key) == false)
		throw BitcoinExchange::BadInputException();
	if (value < 0)
		throw BitcoinExchange::NegativeValueException();
	if (value > 1000)
		throw BitcoinExchange::TooLargeValueException();
	
	std::map<std::string, double>::const_iterator iter = db.find(key);
	if (iter == db.end())
	{
		iter = db.lower_bound(key);
		if (iter == db.begin())
			throw BitcoinExchange::BadInputException();
		--iter;
	}
	return (iter->second * value);
}

void	BitcoinExchange::print()
{
	std::map<std::string, double>::iterator iter;
	for (iter = this->db.begin(); iter != this->db.end(); iter++)
		std::cout << iter->first << ": " << iter->second << std::endl;
}

const char* BitcoinExchange::CouldNotOpenCSVException::what() const throw()
{
	return "Error: could not open .csv file.";
}

const char* BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
	return "Error: could not open file.";
}

const char* BitcoinExchange::NegativeValueException::what() const throw()
{
	return "Error: not a positive number.";
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
	return "Error: bad input";
}

const char* BitcoinExchange::TooLargeValueException::what() const throw()
{
	return "Error: too large a number.";
}
