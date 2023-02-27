/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 19:03:52 by jungeun           #+#    #+#             */
/*   Updated: 2023/02/26 22:13:05 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	Contact::getFirstName(void)
{
	return this->first_name;
}

std::string	Contact::getLastName(void)
{
	return this->last_name;
}

std::string	Contact::getNickname(void)
{
	return this->nickname;
}

std::string	Contact::getPhoneNumber(void)
{
	return this->phone_number;
}

std::string	Contact::getDarkestSecret(void)
{
	return this->darkest_secret;
}

void	Contact::setFirstName(std::string input)
{
	this->first_name = input;
}

void	Contact::setLastName(std::string input)
{
	this->last_name = input;
}

void	Contact::setNickname(std::string input)
{
	this->nickname = input;
}

void	Contact::setPhoneNumber(std::string input)
{
	this->phone_number = input;
}

void	Contact::setDarkestSecret(std::string input)
{
	this->darkest_secret = input;
}
