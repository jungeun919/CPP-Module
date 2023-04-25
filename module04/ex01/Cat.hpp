/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:03 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:19:21 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain	*brain;
	
	public:
		Cat(void);
		Cat(const Cat& object);
		~Cat(void);
		Cat&	operator=(const Cat& object);

		void		makeSound(void) const;
		Brain*		getBrain(void) const;
};

#endif
