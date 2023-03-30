/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:13:58 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/29 21:35:24 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	Point::getArea(const Point &p1, const Point &p2, const Point &p3)
{
	Fixed	set1;
	Fixed	set2;
	Fixed	big;
	Fixed	small;

	set1 = p1.getX() * p2.getY() + p2.getX() * p3.getY() + p3.getX() * p1.getY();
	set2 = p1.getY() * p2.getX() + p2.getY() * p3.getX() + p3.getY() * p1.getX();
	big = Fixed::max(set1, set2);
	small = Fixed::min(set1, set2);
	return (big - small) / 2;
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	area;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	area = Point::getArea(a, b, c);
	area1 = Point::getArea(a, b, point);
	area2 = Point::getArea(b, c, point);
	area3 = Point::getArea(c, a, point);

	if ((area == area1 + area2 + area3) && (area1 * area2 * area3 != 0))
		return true;
	else
		return false;
}
