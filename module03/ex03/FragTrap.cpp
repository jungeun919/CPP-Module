/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:28:34 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/24 16:36:23 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& object)
{
	*this = object;
	std::cout << "FragTrap " << this->name << " copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& object)
{
	if (this != &object)
	{
		this->name = object.name;
		this->hitPoints = object.hitPoints;
		this->energyPoints = object.energyPoints;
		this->attackDamage = object.attackDamage;
	}
	std::cout << "FragTrap " << this->name << " copy assignment operator called" << std::endl;
	return *this;
}

void	FragTrap::attack(const std::string& target)
{
	if (!this->hitPoints)
	{
		std::cout << "FragTrap " << this->name << "is died" << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "FragTrap " << this->name << " has no energyPoints" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "FragTrap " << this->name << " attakcs " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->hitPoints)
	{
		std::cout << "FragTrap " << this->name << "is died" << std::endl;
		return;
	}
	std::cout << "FragTrap " << this->name << " high five~" << std::endl;
}
