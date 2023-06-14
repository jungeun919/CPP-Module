/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:16:38 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/14 14:44:52 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

struct Data
{
	std::string	_name;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& object);
		~Serializer(void);
		Serializer&	operator=(const Serializer& object);
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
