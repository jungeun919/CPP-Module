/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:50:14 by jungeun           #+#    #+#             */
/*   Updated: 2023/04/12 12:44:54 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	this->name = "default diamond name";
	this->energyPoints = 50;
	std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
	printStatus();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->name = name;
	this->energyPoints = 50;
	std::cout << "DiamondTrap " << this->name << " constructor called" << std::endl;
	printStatus();
}

DiamondTrap::DiamondTrap(const DiamondTrap& object) : ClapTrap(), ScavTrap(), FragTrap()
{
	*this = object;
	std::cout << "DiamondTrap " << this->name << " copy constructor called" << std::endl;
	printStatus();
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->name << " destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& object)
{
	if (this != &object)
	{
		ClapTrap::name = object.name + "_clap_name";
		this->name = object.name;
		this->hitPoints = object.hitPoints;
		this->energyPoints = object.energyPoints;
		this->attackDamage = object.attackDamage;
	}
	std::cout << "DiamondTrap " << this->name << " copy assignment operator called" << std::endl;
	printStatus();
	return *this;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name is " << this->name
		<< ", ClapTrap name is " << ClapTrap::name << std::endl;
}

void	DiamondTrap::printStatus(void)
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "hitPoints: " << this->hitPoints << std::endl;
	std::cout << "energyPoints: " << this->energyPoints << std::endl;
	std::cout << "attackDamage: " << this->attackDamage << std::endl;
}
