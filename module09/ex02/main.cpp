/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:49 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 02:04:22 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<int>	input;
	time_t				start;
	time_t				end;
	double				result;

	try
	{
		if (argc < 2)
			throw ErrorException();
		
		input = checkInput(argc, argv);
		std::cout << "Before: ";
		printContainer(input);

		std::cout << "After (std::vector): ";
		printContainer(vectorFordJohnson(input));

		std::cout << "After (std::list)  : ";
		printContainer(listFordJohnson(input));
		
		start = clock();
		vectorFordJohnson(input);
		end = clock();
		result = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process a range of " << input.size() << " elements with std::vector : " << result << "ms" << std::endl;

		start = clock();
		listFordJohnson(input);
		end = clock();
		result = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
		std::cout << "Time to process a range of " << input.size() << " elements with std::list   : " << result << "ms" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}
