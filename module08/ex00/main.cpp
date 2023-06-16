/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:29:55 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/16 14:29:56 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <deque>
#include <iostream>
#include "easyfind.hpp"

int	main()
{
	{
		std::cout << "[vector test]" << std::endl;

		std::vector<int> v;

		for (int i = 0; i < 10; i++)
			v.push_back(i);
		
		try
		{
			std::cout << *easyfind(v, 5) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << *easyfind(v, -1) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl;
	
	{
		std::cout << "[deque test]" << std::endl;

		std::deque<int> d;

		for (int i = 0; i < 10; i++)
			d.push_back(i);
		
		try
		{
			std::cout << *easyfind(d, 5) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			std::cout << *easyfind(d, -1) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}
