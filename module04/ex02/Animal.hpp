/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:55 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 01:47:18 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string		type;

	public:
		Animal(void);
		Animal(const Animal& object);
		virtual ~Animal(void);
		Animal&	operator=(const Animal& object);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
