/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:24:33 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/24 15:56:41 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& object)
{
	*this = object;
	std::cout << "ClapTrap " << this->name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& object)
{
	if (this != &object)
	{
		this->name = object.name;
		this->hitPoints = object.hitPoints;
		this->energyPoints = object.energyPoints;
		this->attackDamage = object.attackDamage;
	}
	std::cout << "ClapTrap" << this->name << " copy assignment operator called" << std::endl;
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << "is died" << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " has no energyPoints" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " attakcs " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is died" << std::endl;
		return;
	}
	if (this->hitPoints > amount)
	{
		std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage" << std::endl;
		this->hitPoints -= amount;
	}
	else
	{
		std::cout << "ClapTrap " << this->name << " is died" << std::endl;
		this->hitPoints = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "ClapTrap " << this->name << " is died" << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ClapTrap " << this->name << " has no energyPoints" << std::endl;
		return;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	std::cout << "ClapTrap " << this->name << " has repaired with " << amount << " hitPoints" << std::endl;
}
