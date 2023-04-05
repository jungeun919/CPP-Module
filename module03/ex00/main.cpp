/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:24:43 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/24 16:13:19 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	clapTrapA("A");
	ClapTrap	clapTrapB("B");

	std::cout << std::endl;

	clapTrapA.attack("B");
	clapTrapB.takeDamage(5);
	clapTrapB.beRepaired(3);

	clapTrapB.attack("A");
	clapTrapA.takeDamage(10);
	clapTrapA.beRepaired(10);
	
	std::cout << std::endl;
	
	return 0;
}
