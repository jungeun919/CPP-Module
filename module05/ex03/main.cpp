/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:37 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 03:06:40 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	{
		Bureaucrat	jungchoi("jungchoi", 1);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

		jungchoi.signForm(*rrf);
		jungchoi.executeForm(*rrf);

		delete rrf;
	}

	std::cout << std::endl;
	
	{
		Bureaucrat	jungchoi("jungchoi", 150);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("RobotomyRequestForm", "Bender");

		jungchoi.signForm(*rrf);
		jungchoi.executeForm(*rrf);

		delete rrf;
	}
	
	return 0;
}
