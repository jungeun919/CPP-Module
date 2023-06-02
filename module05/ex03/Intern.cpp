/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 02:59:21 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 03:05:03 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern& object)
{
	*this = object;
}

Intern::~Intern(void)
{
}

Intern&	Intern::operator=(const Intern& object)
{
	if (this != &object)
		*this = object;
	return *this;
}

static AForm	*makePresidentialPardonForm(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

static AForm	*makeRobotomyRequestForm(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm	*makeShrubberyCreationForm(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::makeForm(std::string formName, const std::string &target)
{
	std::string	types[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*(*forms[3])(const std::string &target) = {&makePresidentialPardonForm, &makeRobotomyRequestForm, &makeShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (types[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i](target);
		}
	}
	throw FormNotFoundException();
}

const char*	Intern::FormNotFoundException::what(void) const throw()
{
	return "Form not found";
}
