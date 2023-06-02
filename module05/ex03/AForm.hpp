/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:09:42 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 12:20:53 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
		
	public:
		AForm(void);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& object);
		virtual ~AForm(void);
		AForm&	operator=(const AForm& object);

		const std::string&	getName(void) const;
		bool				getIsSigned(void) const;
		const int&			getGradeToSign(void) const;
		const int&			getGradeToExecute(void) const;

		void			beSigned(const Bureaucrat &bureaucrat); //const 위치?
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
		class NotSignedException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& out, const AForm& object);

#endif
