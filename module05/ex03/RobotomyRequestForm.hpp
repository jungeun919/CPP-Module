/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:14:16 by jungeun           #+#    #+#             */
/*   Updated: 2023/05/11 02:58:16 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	target;
		
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& object);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& object);

		void	execute(Bureaucrat const &executor) const;
};

#endif
