/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 20:54:29 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:57:10 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& object);
		~Bureaucrat(void);
		Bureaucrat&	operator=(const Bureaucrat& object);

		const std::string&	getName(void) const;
		int					getGrade(void) const;
		
		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(AForm& form);
		void	executeForm(AForm const & form);
		
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

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& object);

#endif
