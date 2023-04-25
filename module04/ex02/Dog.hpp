/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:11 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:21:21 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*brain;
		
	public:
		Dog(void);
		Dog(const Dog& object);
		~Dog(void);
		Dog&	operator=(const Dog& object);

		void		makeSound(void) const;
		Brain*		getBrain(void) const;
};

#endif
