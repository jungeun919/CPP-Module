/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:24:43 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/24 16:12:53 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	scavTrapA("A");
	ScavTrap	scavTrapB("B");

	std::cout << std::endl;
	
	scavTrapA.attack("B");
	scavTrapB.takeDamage(5);
	scavTrapB.beRepaired(3);

	scavTrapB.attack("A");
	scavTrapA.takeDamage(10);
	scavTrapA.beRepaired(10);

	scavTrapA.guardGate();
	
	std::cout << std::endl;
	
	return 0;
}
