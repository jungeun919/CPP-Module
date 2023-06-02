/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:10 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 12:20:28 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object) : AForm(object), target(object.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& object)
{
	if (this != &object)
		AForm::operator=(object);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << "drilling noises👂" << std::endl;
	if (time(NULL) % 2)
		std::cout << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->target << " has been robotomized failure." << std::endl;
}
