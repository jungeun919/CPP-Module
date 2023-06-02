/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:54:41 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:28:11 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main()
{
	{
		std::cout << "[valid value test (no exception)]" << std::endl;

		try
		{
			Bureaucrat	jungchoi1("jungchoi1", 2);
			Bureaucrat	jungchoi2("jungchoi2", 10);
			Form		form("cadetForm", 10, 1);

			std::cout << form << std::endl;

			jungchoi1.signForm(form);
			jungchoi2.signForm(form);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << std::endl;

	{
		std::cout << "[invalid value test (exception)]" << std::endl;

		try
		{
			Bureaucrat	jungchoi1("jungchoi1", 11);
			Form		form("cadetForm", 10, 1);

			std::cout << form << std::endl;

			jungchoi1.signForm(form);
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
			Form	form1("form1", 10, 1);
			Form	form2("form2", 1, 0); // exception
			Form	form3("form3", 151, 150); // exception
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	return 0;
}
