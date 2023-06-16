/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:29:50 by jungeun           #+#    #+#             */
/*   Updated: 2023/06/16 14:29:51 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator iter;
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw std::runtime_error("value not found");
	return iter;
}

#endif
