/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:09:37 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 12:20:19 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& object) : name(object.name), isSigned(object.isSigned), gradeToSign(object.gradeToSign), gradeToExecute(object.gradeToExecute)
{
}

AForm::~AForm(void)
{
}

AForm&	AForm::operator=(const AForm& object)
{
	if (this != &object)
		this->isSigned = object.isSigned;
	return *this;
}

const std::string&	AForm::getName(void) const
{
	return this->name;
}

bool	AForm::getIsSigned(void) const
{
	return this->isSigned;
}

const int&	AForm::getGradeToSign(void) const
{
	return this->gradeToSign;
}

const int&	AForm::getGradeToExecute(void) const
{
	return this->gradeToExecute;
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->gradeToSign < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

const char*	AForm::NotSignedException::what(void) const throw()
{
	return "Form is not signed";
}

std::ostream&	operator<<(std::ostream& out, const AForm& object)
{
	out << object.getName()
		<< ", AForm isSigned " << object.getIsSigned()
		<< ", AForm gradeToSign " << object.getGradeToSign()
		<< ", AForm gradeToExecute " << object.getGradeToExecute()
		<< ".";
	return out;
}
