/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:16:28 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/09 12:23:21 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main()
{
	Data			data;
	Serialization	serialization;

	data._name = "jungchoi";

	uintptr_t	raw = serialization.serialize(&data);

	std::cout << "[serialize]" << std::endl;
	std::cout << "data address: " << (uintptr_t)&data << std::endl;
	std::cout << "raw value: " << raw << std::endl;
	std::cout << "raw value (hex): " << std::hex << raw << std::endl;

	std::cout << std::endl;
	
	Data*	ptr = serialization.deserialize(raw);

	std::cout << "[deserialize]" << std::endl;
	std::cout << "ptr address: " << ptr << std::endl;
	std::cout << "data address: " << &data << std::endl;
	std::cout << "ptr value: " << ptr->_name << std::endl;
	std::cout << "data value: " << data._name << std::endl;

	return 0;
}
