/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:09:51 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:45:13 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	target;
		
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& object);
		~PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& object);

		void	execute(Bureaucrat const &executor) const;
};

#endif
