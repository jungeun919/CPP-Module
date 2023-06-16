/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:30:14 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/16 14:39:45 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : size(0)
{
}

Span::Span(unsigned int n) : size(n)
{
}

Span::Span(const Span& object)
{
	*this = object;
}

Span::~Span(void)
{
}

Span&	Span::operator=(const Span& object)
{
	if (this != &object)
	{
		size = object.size;
		arr = object.arr;
	}
	return *this;
}

void	Span::addNumber(int num)
{
	if (arr.size() == size)
		throw std::exception();
	arr.push_back(num);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	// if (arr.size() + (end - begin) > size)
	if (arr.size() + std::distance(begin, end) > size)
		throw std::exception();
	arr.insert(arr.end(), begin, end);
}

int		Span::shortestSpan(void)
{
	if (arr.size() < 2)
		throw std::logic_error("arr size is not over 2");
	
	std::vector<int> tempArr(arr);
	std::sort(tempArr.begin(), tempArr.end());

	int min = INT_MAX;
	for (unsigned int i = 0; i < size - 1; i++)
	{
		int tempDiff = tempArr[i + 1] - tempArr[i];
		if (tempDiff < min)
			min = tempDiff;
	}
	return min;
}

int		Span::longestSpan(void)
{
	if (arr.size() < 2)
		throw std::logic_error("arr size is not over 2");
	
	std::vector<int> tempArr(arr);
	std::sort(tempArr.begin(), tempArr.end());

	return tempArr[tempArr.size() - 1] - tempArr[0];
	// return tempArr.back() - tempArr.front();
}
