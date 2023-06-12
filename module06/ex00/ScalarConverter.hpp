/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 01:12:55 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/12 15:08:33 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib> // strtod
# include <cctype> // isprint
# include <limits> // numeric_limits
# include <iomanip> // setprecision

class ScalarConverter
{	
	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& object);
		~ScalarConverter(void);
		ScalarConverter&	operator=(const ScalarConverter& object);

		static void		convert(std::string input);
		static int		checkType(std::string input);
};

#endif
