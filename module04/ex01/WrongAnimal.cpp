/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:24 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/20 13:12:25 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& object)
{
	this->type = object.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& object)
{
	if (this != &object)
		this->type = object.type;
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound👂" << std::endl;
}
