/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:11:33 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/05 22:25:44 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& object)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = object;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->value = value << this->bit;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << this->bit));
}

Fixed&	Fixed::operator=(const Fixed& object)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &object)
		this->value = object.getRawBits();
	return *this;
}

bool	Fixed::operator>(const Fixed& object) const
{
	return this->value > object.getRawBits();
}

bool	Fixed::operator<(const Fixed& object) const
{
	return this->value < object.getRawBits();
}

bool	Fixed::operator>=(const Fixed& object) const
{
	return this->value >= object.getRawBits();
}

bool	Fixed::operator<=(const Fixed& object) const
{
	return this->value <= object.getRawBits();
}

bool	Fixed::operator==(const Fixed& object) const
{
	return this->value == object.getRawBits();
}

bool	Fixed::operator!=(const Fixed& object) const
{
	return this->value != object.getRawBits();
}

Fixed	Fixed::operator+(const Fixed& object) const
{
	return Fixed((toFloat() + object.toFloat()));	
}

Fixed	Fixed::operator-(const Fixed& object) const
{
	return Fixed((toFloat() - object.toFloat()));	
}

Fixed	Fixed::operator*(const Fixed& object) const
{
	return Fixed((toFloat() * object.toFloat()));	
}

Fixed	Fixed::operator/(const Fixed& object) const
{
	return Fixed((toFloat() / object.toFloat()));	
}

Fixed&	Fixed::operator++()
{
	this->value++;
	return *this;
}

Fixed&	Fixed::operator--()
{
	this->value--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	operator++();
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	operator--();
	return temp;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return a < b ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return a > b ? a : b;
}

const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	return a < b ? a : b;
}

const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	return a > b ? a : b;
}

std::ostream&	operator<<(std::ostream& out, const Fixed& object)
{
	out << object.toFloat();
	return out;
}
