/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:16 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 16:27:46 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		std::cout << "[Test subject]" << std::endl;

		const Animal*	animal = new Animal();
		const Animal*	dog = new Dog();
		const Animal*	cat = new Cat();

		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		
		cat->makeSound(); //will output the cat sound!
		dog->makeSound();
		animal->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}
	{
		std::cout << "[Test WrongAnimal (virtual x)]" << std::endl;

		const WrongAnimal*	wrongAnimal = new WrongAnimal();
		const WrongAnimal*	wrongCat = new WrongCat();

		std::cout << wrongCat->getType() << " " << std::endl;

		wrongCat->makeSound();
		wrongAnimal->makeSound();

		delete wrongAnimal;
		delete wrongCat;
	}

	system("leaks a.out");
	
	return 0;
}
