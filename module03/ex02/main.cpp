/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:24:43 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/29 20:06:28 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main()
{
	FragTrap	fragTrapA("A");
	FragTrap	fragTrapB("B");

	std::cout << std::endl;
	
	fragTrapA.attack("B");
	fragTrapB.takeDamage(5);
	fragTrapB.beRepaired(3);

	fragTrapB.attack("A");
	fragTrapA.takeDamage(10);
	fragTrapA.beRepaired(10);

	fragTrapA.highFivesGuys();
	
	std::cout << std::endl;
	
	return 0;
}
