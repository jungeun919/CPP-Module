/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:11:33 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/05 22:23:52 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bit;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bit));
}

Fixed&	Fixed::operator=(const Fixed& object)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
		this->value = object.getRawBits();
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::toInt(void) const
{
	return this->value >> this->bit;
}

float	Fixed::toFloat(void) const
{
	return (float)this->value / (1 << this->bit);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& object)
{
	out << object.toFloat();
	return out;
}
