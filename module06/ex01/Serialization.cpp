/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:16:33 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/09 12:20:16 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization(void)
{
}

Serialization::Serialization(const Serialization& object)
{
	*this = object;
}

Serialization::~Serialization(void)
{
}

Serialization&	Serialization::operator=(const Serialization& object)
{
	(void)object;
	return *this;
}

uintptr_t	Serialization::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serialization::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
