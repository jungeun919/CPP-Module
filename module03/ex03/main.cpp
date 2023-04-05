/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:24:43 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/26 05:13:49 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	diamondTrapA("A");
	DiamondTrap	diamondTrapB("B");

	std::cout << std::endl;
	
	diamondTrapA.whoAmI();
	diamondTrapB.whoAmI();

	std::cout << std::endl;
	
	diamondTrapA.attack("B");
	diamondTrapB.takeDamage(5);
	diamondTrapB.beRepaired(3);

	diamondTrapB.attack("A");
	diamondTrapA.takeDamage(10);
	diamondTrapA.beRepaired(10);

	diamondTrapA.highFivesGuys();
	
	std::cout << std::endl;
	
	return 0;
}
