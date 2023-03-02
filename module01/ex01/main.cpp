/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 23:32:52 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/02 23:41:54 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	n = 10;
	Zombie	*zombies = zombieHorde(n, "jungchoi");
	for (int i = 0; i < n; i++)
		zombies[i].announce();
	delete[] zombies;

	system("leaks zombie");

	return 0;
}
