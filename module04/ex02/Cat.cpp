/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:59 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:28:45 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& object)
{
	this->type = object.type;
	this->brain = new Brain(*object.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& object)
{
	if (this != &object)
	{
		delete this->brain;
		this->type = object.type;
		this->brain = new Brain(*object.brain);
	}
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat sound👂" << std::endl;
}

Brain*	Cat::getBrain(void) const
{
	return this->brain;
}
