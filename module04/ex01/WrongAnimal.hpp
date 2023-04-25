/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:28 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/20 13:12:28 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string		type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& object);
		virtual ~WrongAnimal(void);
		WrongAnimal&	operator=(const WrongAnimal& object);

		std::string	getType(void) const;
		void		makeSound(void) const;
};

#endif
