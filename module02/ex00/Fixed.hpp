/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:15:52 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/23 16:15:53 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	bit = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& object);
		Fixed&	operator=(const Fixed& object);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
