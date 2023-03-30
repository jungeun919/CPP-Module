/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:01:00 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/30 12:09:37 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main()
{
	Point	a(3, 0);
	Point	b(3, 3);
	Point	c(0, 3);
	Point	p(2, 2);

	std::cout << "A.x : " << a.getX() << "	A.y : " << a.getY() << std::endl;
	std::cout << "B.x : " << b.getX() << "	B.y : " << b.getY() << std::endl;
	std::cout << "C.x : " << c.getX() << "	C.y : " << c.getY() << std::endl;
	std::cout << "P.x : " << p.getX() << "	P.y : " << p.getY() << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "P is in the triangle" << std::endl;
	else
	 	std::cout << "P isn't in the triangle" << std::endl;
	
	return 0;	
}
