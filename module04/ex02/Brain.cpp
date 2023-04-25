/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:29:59 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/25 03:26:30 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& object)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = object.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& object)
{
	if (this != &object)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = object.ideas[i];
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

std::string	Brain::getIdea(int n) const
{
	return this->ideas[n];
}

void	Brain::setIdea(std::string idea, int n)
{
	this->ideas[n] = idea;
}
