/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 01:12:55 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/09 07:50:32 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string> // add
# include <cstdlib> // strtod ()
# include <cctype> // isprint ()
# include <limits> // numeric_limits
# include <iomanip> // setprecision

class Converter
{	
	public:
		Converter(void); // C# 에서 static class private
		Converter(const Converter& object);
		~Converter(void);
		Converter&	operator=(const Converter& object);

		static void	convert(std::string input);
		static int		checkType(std::string input);
};

#endif
