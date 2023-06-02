/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:09:47 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 12:20:14 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object) : AForm(object), target(object.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& object)
{
	if (this != &object)
		AForm::operator=(object);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
