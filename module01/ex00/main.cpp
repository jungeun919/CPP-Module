/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:11:09 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/02 23:11:11 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	zombie1 = Zombie("jungchoi");
	zombie1.announce();

	randomChump("random");

	Zombie	*zombie2 = newZombie("new jungchoi");
	zombie2->announce();
	delete zombie2;

	system("leaks zombie");

	return 0;
}
