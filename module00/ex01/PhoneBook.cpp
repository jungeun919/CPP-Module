/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 15:56:04 by jungeun           #+#    #+#             */
/*   Updated: 2023/02/28 23:41:18 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PHONEBOOK CREATED" << std::endl;
	index = 0;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PHONEBOOK DESTROYED" << std::endl;
}

void	PhoneBook::add(void)
{
	std::string	input;

	std::cout << "Enter first name: ";
	input = getContactInfo();
	contact[index].setFirstName(input);

	std::cout << "Enter last name: ";
	input = getContactInfo();
	contact[index].setLastName(input);

	std::cout << "Enter nickname: ";
	input = getContactInfo();
	contact[index].setNickname(input);

	std::cout << "Enter phone number: ";
	input = getContactInfo();
	contact[index].setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	input = getContactInfo();
	contact[index].setDarkestSecret(input);

	index += 1;
}

std::string	PhoneBook::getContactInfo(void)
{
	std::string	input;

	while (1)
	{
		input.clear();
		std::getline(std::cin, input);
		if (std::cin.eof() == true)
			exit(0);
		else if (input.size() > 0)
			break;
		else
			std::cout << "Re-enter: ";
	}
	return (input);
}

void	PhoneBook::search(void)
{	
	std::string	input;
	
	if (index == 0)
	{
		std::cout << "Empty contact" << std::endl;
		return;
	}
	
	std::cout << "|" << std::setw(10) << "Index"
		<< "|" << std::setw(10) << "FirstName"
		<< "|" << std::setw(10) << "LastName"
		<< "|" << std::setw(10) << "Nickname"
		<< "|" << std::endl;

	for (int i = 0; i < index; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1
			<< "|" << std::setw(10) << checkColumn(contact[i].getFirstName())
			<< "|" << std::setw(10) << checkColumn(contact[i].getLastName())
			<< "|" << std::setw(10) << checkColumn(contact[i].getNickname())
			<< "|" << std::endl;
	}
	
	while (1)
	{
		std::cout << "Enter the index: ";
		std::getline(std::cin, input);

		if (std::cin.eof() == true)
			exit(0);
		if (input.size() == 0 || input < "1" || input > "8" || std::stoi(input) > index)
		{
			std::cin.clear();
			std::cout << "Invalid index" << std::endl;
		}
		else
			break;
	}
	
	std::cout << "FirstName: " << contact[std::stoi(input) - 1].getFirstName() << std::endl
		<< "LastName: " << contact[std::stoi(input) - 1].getLastName() << std::endl
		<< "Nickname: " << contact[std::stoi(input) - 1].getNickname() << std::endl
		<< "PhoneNumber: " << contact[std::stoi(input) - 1].getPhoneNumber() << std::endl
		<< "DarkestSecret: " << contact[std::stoi(input) - 1].getDarkestSecret() << std::endl;
}

std::string	PhoneBook::checkColumn(std::string column)
{
	if (column.size() > 10)
		column = column.substr(0, 9) + ".";
	return column;
}
