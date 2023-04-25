/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:59 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/20 13:12:00 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& object)
{
	this->type = object.type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& object)
{
	if (this != &object)
		this->type = object.type;
	std::cout << "Cat copy assignment operator called" << std::endl;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat sound👂" << std::endl;
}
