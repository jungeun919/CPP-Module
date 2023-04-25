/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:50 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/20 13:11:51 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal& object)
{
	this->type = object.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& object)
{
	if (this != &object)
		this->type = object.type;
	std::cout << "Animal copy assignment operator called" << std::endl;
	return *this;
}

std::string	Animal::getType(void) const
{
	return this->type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal sound👂" << std::endl;
}
