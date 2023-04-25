/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:07 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:21:35 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& object)
{
	this->type = object.type;
	this->brain = new Brain(*object.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& object)
{
	if (this != &object)
	{
		delete this->brain;
		this->type = object.type;
		this->brain = new Brain(*object.brain);
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog sound👂" << std::endl;
}

Brain*	Dog::getBrain(void) const
{
	return this->brain;
}
