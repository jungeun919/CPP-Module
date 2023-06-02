/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 02:59:25 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 03:05:32 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{		
	public:
		Intern(void);
		Intern(const Intern& object);
		~Intern(void);
		Intern&	operator=(const Intern& object);

		AForm	*makeForm(std::string formName, const std::string &target);
		
		class FormNotFoundException : public std::exception
		{
			public:
				const char* what(void) const throw();
		};
};

#endif
