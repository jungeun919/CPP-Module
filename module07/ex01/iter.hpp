/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:48:29 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/12 14:48:30 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T> 
void	iter(T *array, unsigned int length, void (*func)(T &))
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}

template<typename T> 
void	print(T &obj)
{
	std::cout << obj << std::endl;
}

#endif
