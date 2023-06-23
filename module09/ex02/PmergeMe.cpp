/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:28:55 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/23 15:23:34 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	checkInput(int argc, char **argv)
{
	std::vector<int>	input;
	std::string			stringNum;
	int					num;

	for (int i = 1; i < argc; i++)
	{
		stringNum = argv[i];
		std::istringstream ss(stringNum);

		ss >> num;
		if (num <= 0)
			throw ErrorException();
		input.push_back(num);
	}
	return input;
}

bool	compare(std::pair<int, int> a, std::pair<int, int> b)
{
	return a.second < b.second;
}

// std::ostream& operator<<(std::ostream& out, const std::pair<int, int>& p) {
// 	out << "(" << p.first << ", " << p.second << ")";
// 	return out;
// }

std::vector<int>	vectorFordJohnson(std::vector<int> input)
{
	std::vector< std::pair<int, int> >	pairs;
	std::vector<int>					result;

	if (input.size() == 1)
		return input;
	
	pairs = makePairs< std::vector< std::pair<int, int> > >(input);
	sort(pairs.begin(), pairs.end(), compare);

	result = makeResult< std::vector<int>, std::vector< std::pair<int, int> > >(pairs);
	result.resize(input.size());
	
	// main chain
	size_t	jacobsthal[20] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	size_t	pendSize = input.size() / 2 - 1;

	std::vector<int>::iterator	endIter = result.begin();
	std::vector<int>::iterator	resultIter;
	std::pair<int, int>			target;

	int	jacobIdx = 0;
	int	jacobVal = 1;
	int	idx = 1;

	while (pendSize-- > 0)
	{
		if (jacobVal == idx)
		{
			jacobVal = jacobsthal[jacobIdx];
			jacobIdx++;
			idx = jacobsthal[jacobIdx] <= input.size() / 2 ? jacobsthal[jacobIdx] : input.size() / 2;

			target = pairs[idx - 1];
			while (target.second != *endIter)
				endIter++;
		}
		else
		{
			target = pairs[idx - 1];
			while (target.second != *endIter)
				endIter--;
		}
		result.pop_back();
		resultIter = std::lower_bound(result.begin(), endIter, target.first);
		result.insert(resultIter, target.first);

		endIter++;
		idx--;
	}
	if (input.size() % 2 == 1)
	{
		result.pop_back();
		resultIter = std::lower_bound(result.begin(), result.end(), input.back());
		result.insert(resultIter, input.back());
	}
	return result;
}

std::list<int>	listFordJohnson(std::vector<int> input)
{
	std::list< std::pair<int, int> >	pairs;
	std::list<int>						result;

	if (input.size() == 1)
		return std::list<int>(1, input[0]);
	
	pairs = makePairs< std::list< std::pair<int, int> > >(input);
	pairs.sort(compare);
	
	result = makeResult< std::list<int>, std::list< std::pair<int, int> > >(pairs);
	
	// main chain
	size_t	jacobsthal[20] = { 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
	size_t	pendSize = input.size() / 2 - 1;

	std::list< std::pair<int, int> >::iterator	pairIter = pairs.begin();
	std::list<int>::iterator					endIter = result.begin();
	std::list<int>::iterator					resultIter;
	std::pair<int, int>							target;

	int	jacobIdx = 0;
	int	jacobVal = 1;
	int	idx = 1;

	while (pendSize-- > 0)
	{
		if (jacobVal == idx)
		{
			idx = jacobsthal[jacobIdx + 1] <= input.size() / 2 ? jacobsthal[jacobIdx + 1] : input.size() / 2;
			for (int i = jacobVal; i < idx; i++)
				pairIter++;
			jacobVal = jacobsthal[jacobIdx];
			jacobIdx++;

			target = *pairIter;
			while (target.second != *endIter)
				endIter++;
		}
		else
		{
			target = *pairIter;
			while (target.second != *endIter)
				endIter--;
		}
		resultIter = std::lower_bound(result.begin(), endIter, target.first);
		result.insert(resultIter, target.first);

		endIter++;
		pairIter--;
		idx--;
	}
	if (input.size() % 2 == 1)
	{
		resultIter = std::lower_bound(result.begin(), result.end(), input.back());
		result.insert(resultIter, input.back());
	}
	return result;
}

const char*	ErrorException::what() const throw()
{
	return "Error";
}
