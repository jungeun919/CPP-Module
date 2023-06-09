/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:16:38 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/09 12:16:50 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <cstdint>

struct Data
{
	std::string	_name;
};

class Serialization
{
	public:
		Serialization(void);
		Serialization(const Serialization& object);
		~Serialization(void);
		Serialization&	operator=(const Serialization& object);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
