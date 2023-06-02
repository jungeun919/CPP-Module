/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:21 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 12:21:33 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& object) : AForm(object), target(object.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& object)
{
	if (this != &object)
		AForm::operator=(object);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename);
	if (outfile.is_open() == false)
		std::cout << "Failed to open " << filename << std::endl;
	else
	{
		outfile << "       ###" << std::endl;
		outfile << "      #o###" << std::endl;
		outfile << "    #####o###" << std::endl;
		outfile << "   #o###|#/###" << std::endl;
		outfile << "    ####|/#o#" << std::endl;
		outfile << "     # }|{  #" << std::endl;
		outfile << "       }|{" << std::endl;
		outfile.close();
		std::cout << this->target << " create shrubbery file." << std::endl;
	}
}
