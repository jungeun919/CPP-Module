/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:54:41 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:15:39 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	{
		std::cout << "[boundary value test]" << std::endl;
		
		try
		{
			Bureaucrat	high("high", 1);
			Bureaucrat	low("low", 150);
			Bureaucrat	mid("mid", 75);

			std::cout << high << std::endl;
			std::cout << low << std::endl;
			std::cout << mid << std::endl;

			high.incrementGrade(); // exception
			low.decrementGrade(); // exception
			mid.incrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl;

	{
		std::cout << "[constructor invalid value test]" << std::endl;

		try
		{
			Bureaucrat	bureaucrat1("anonymous1", 0); // exception
			Bureaucrat	bureaucrat2("anonymous2", 151); // exception
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}
