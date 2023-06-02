/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:20:06 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:22:17 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& object) : name(object.name), isSigned(object.isSigned), gradeToSign(object.gradeToSign), gradeToExecute(object.gradeToExecute)
{
}

Form::~Form(void)
{
}

Form&	Form::operator=(const Form& object)
{
	if (this != &object)
		this->isSigned = object.isSigned;
	return *this;
}

const std::string&	Form::getName(void) const
{
	return this->name;
}

bool	Form::getIsSigned(void) const
{
	return this->isSigned;
}

const int&	Form::getGradeToSign(void) const
{
	return this->gradeToSign;
}

const int&	Form::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->gradeToSign < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& out, const Form& object)
{
	out << object.getName()
		<< ", form isSigned " << object.getIsSigned()
		<< ", form gradeToSign " << object.getGradeToSign()
		<< ", form gradeToExecute " << object.getGradeToExecute()
		<< ".";
	return out;
}
