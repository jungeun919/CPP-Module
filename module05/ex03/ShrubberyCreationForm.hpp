/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:26 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:59:05 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	target;
		
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& object);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& object);

		void	execute(Bureaucrat const &executor) const;
};

#endif
