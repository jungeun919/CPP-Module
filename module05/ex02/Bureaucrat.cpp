/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:54:24 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:35:07 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& object) : name(object.name), grade(object.grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& object)
{
	if (this != &object)
		this->grade = object.grade;
	return *this;
}

const std::string&	Bureaucrat::getName(void) const
{
	return this->name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->grade;
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& object)
{
	out << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return out;
}
