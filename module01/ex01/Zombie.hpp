/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:11:25 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/02 23:37:48 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	setName(std::string name);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
