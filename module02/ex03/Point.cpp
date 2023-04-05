/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:07:58 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/05 22:25:53 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(const Point& object) : x(object.x), y(object.y)
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point::Point(const int x, const int y) : x(x), y(y)
{
	// std::cout << "Int constructor called" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	// std::cout << "Float constructor called" << std::endl;
}

Point&	Point::operator=(const Point& object)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	(void)object;
	return *this;
}

Fixed	Point::getX() const
{
	return this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}
