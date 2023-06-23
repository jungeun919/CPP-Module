/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:29:00 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 15:22:20 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <list>
# include <algorithm>
# include <iostream>
# include <sstream>
# include <ctime>

std::vector<int>	checkInput(int argc, char **argv);
bool				compare(std::pair<int, int> a, std::pair<int, int> b);
std::vector<int>	vectorFordJohnson(std::vector<int> input);
std::list<int>		listFordJohnson(std::vector<int> input);

template <typename T>
T	makePairs(std::vector<int> input)
{
	T pairs;

	for (size_t i = 0; i < input.size() - 1; i += 2)
	{
		if (input[i] > input[i + 1])
			pairs.push_back(std::make_pair(input[i + 1], input[i]));
		else
			pairs.push_back(std::make_pair(input[i], input[i + 1]));
	}
	return pairs;
}

template <typename C, typename T>
C	makeResult(T pairInput)
{
	typename T::iterator pairIter;
	C result;

	for (pairIter = pairInput.begin(); pairIter != pairInput.end(); pairIter++)
		result.push_back((*pairIter).second);
	result.insert(result.begin(), pairInput.front().first);
	return result;
}

template <typename T>
void	printContainer(T container)
{
	typename T::iterator iter;
	
	for (iter = container.begin(); iter != container.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

class ErrorException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif
