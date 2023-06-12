/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:48:20 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/12 14:48:21 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T> 
void	swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T> 
T	min(T &a, T &b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

template<typename T> 
T	max(T &a, T &b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

#endif
