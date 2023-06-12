/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:48:43 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/12 14:48:43 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>

template<typename T> 
class Array
{
	private:
		T				*array;
		unsigned int	len;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& object);
		~Array(void);
		Array&	operator=(const Array<T>& object);

		T&	operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;
		unsigned int	size(void);
};

template<typename T>
Array<T>::Array(void)
{
	len = 0;
	array = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	len = n;
}

template<typename T>
Array<T>::Array(const Array& object)
{
	array = new T[object.len];
	for (unsigned int i = 0; i < object.len; i++)
		array[i] = object[i];
	len = object.len;
}

template<typename T>
Array<T>::~Array(void)
{
	if (array)
		delete[] array;
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array<T>& object)
{
	if (this != &object)
	{
		if (array)
			delete[] array;
		array = new T[object.len];
		for (unsigned int i = 0; i < object.len; i++)
			array[i] = object[i];
		len = object.len;
	}
	return *this;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= len)
		throw std::out_of_range("index out of range");
	return array[index];
}

template<typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= len)
		throw std::out_of_range("index out of range");
	return array[index];
}

template<typename T>
unsigned int	Array<T>::size(void)
{
	return len;
}

#endif
