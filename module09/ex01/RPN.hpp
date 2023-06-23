/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:37 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 01:28:37 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class RPN
{
	private:
		RPN();
		RPN(const RPN& object);
		~RPN();
		RPN& operator=(const RPN& object);

	public:
		static void run(std::string input);
		
		class ErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
