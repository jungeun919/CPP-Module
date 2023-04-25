/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:16 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:51:18 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main()
{
	{
		Animal	*animals[4];

		for (int i = 0; i < 4; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << std::endl;

		for (int i = 0; i < 4; i++)
			std::cout << animals[i]->getType() << std::endl;

		std::cout << std::endl;
		
		for (int i = 0; i < 4; i++)
			delete animals[i];
	}
	// {
	// 	Animal	animal;
	// 	Animal	*animal = new Animal();
	// }

	system("leaks a.out");
	
	return 0;
}
