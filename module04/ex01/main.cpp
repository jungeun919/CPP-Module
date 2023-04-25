/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:16 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:35:00 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main()
{
	{
		const Animal	*animals[4];

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
	{
		std::string	str;
		
		Dog	*dog1 = new Dog();
		Dog	*dog2 = new Dog();

		std::cout << std::endl;

		str = dog1->getBrain()->getIdea(0);
		std::cout << "Dog1's first idea is "<< str << std::endl;

		dog1->getBrain()->setIdea("something", 0);
		str = dog1->getBrain()->getIdea(0);
		std::cout << "Dog1's first idea is "<< str << std::endl;

		*dog2 = *dog1;
		str = dog2->getBrain()->getIdea(0);
		std::cout << "Dog2's first idea is "<< str << std::endl;

		std::cout << std::endl;
		
		delete dog1;
		delete dog2;
	}

	system("leaks a.out");
	
	return 0;
}
