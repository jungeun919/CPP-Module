/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:03:34 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/30 12:13:58 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		~Point();
		Point(const Point& object);
		Point(const int x, const int y);
		Point(const float x, const float y);
		Point&	operator=(const Point& object);

		Fixed			getX() const;
		Fixed			getY() const;
		static Fixed	getArea(const Point &p1, const Point &p2, const Point &p3);
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
