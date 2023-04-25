/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:30:03 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 16:28:07 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string		ideas[100];

	public:
		Brain(void);
		Brain(const Brain& object);
		virtual ~Brain(void);
		Brain&	operator=(const Brain& object);

		std::string	getIdea(int n) const;
		void		setIdea(std::string idea, int n);
};

#endif
