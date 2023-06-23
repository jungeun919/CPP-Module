/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:06 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 01:28:06 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	db;

	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange& object);
		~BitcoinExchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange& object);

		void	insert(std::string key, double value);
		bool	isValidDate(const std::string& date) const;
		double	convert(std::string key, double value);

		void	print(void);

		class CouldNotOpenCSVException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class CouldNotOpenFileException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class NegativeValueException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class BadInputException : public std::exception
		{
			virtual const char *what() const throw();
		};

		class TooLargeValueException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

#endif
