/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:20:10 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:31:06 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
		
	public:
		Form(void);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form& object);
		~Form(void);
		Form&	operator=(const Form& object);

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat &bureaucrat);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const Form& object);

#endif
