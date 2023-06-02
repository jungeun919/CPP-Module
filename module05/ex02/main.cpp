/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:37 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:53:28 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << "[ShrubberyCreationForm test]" << std::endl;

		try
		{
			Bureaucrat b1("b1", 1);
			ShrubberyCreationForm s1("s1");
			
			b1.signForm(s1);
			b1.executeForm(s1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		std::cout << "[PresidentialPardonForm test]" << std::endl;

		try
		{
			Bureaucrat b2("b2", 80);
			PresidentialPardonForm p1("p1");

			b2.signForm(p1);
			b2.executeForm(p1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << std::endl;

	{
		std::cout << "[RobotomyRequestForm test]" << std::endl;
		
		try
		{
			Bureaucrat b3("b3", 1);
			RobotomyRequestForm r1("r1");

			b3.signForm(r1);
			b3.executeForm(r1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	
	return 0;
}
