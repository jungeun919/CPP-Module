/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:12:31 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/20 13:12:32 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& object)
{
	this->type = object.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& object)
{
	if (this != &object)
		this->type = object.type;
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	return *this;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound👂" << std::endl;
}
