/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:59:44 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/24 16:25:47 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& object)
{
	*this = object;
	std::cout << "ScavTrap " << this->name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& object)
{
	if (this != &object)
	{
		this->name = object.name;
		this->hitPoints = object.hitPoints;
		this->energyPoints = object.energyPoints;
		this->attackDamage = object.attackDamage;
	}
	std::cout << "ScavTrap " << this->name << " copy assignment operator called" << std::endl;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->hitPoints)
	{
		std::cout << "ScavTrap " << this->name << "is died" << std::endl;
		return;
	}
	if (!this->energyPoints)
	{
		std::cout << "ScavTrap " << this->name << " has no energyPoints" << std::endl;
		return;
	}
	this->energyPoints--;
	std::cout << "ScavTrap " << this->name << " attakcs " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (!this->hitPoints)
	{
		std::cout << "ScavTrap " << this->name << "is died" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " is now in Gate Keeper mode" << std::endl;
}
