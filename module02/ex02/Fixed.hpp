/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungeun <jungeun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:11:24 by jungeun           #+#    #+#             */
/*   Updated: 2023/03/23 21:14:31 by jungeun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bit = 8;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const Fixed& object);
		Fixed(const int value);
		Fixed(const float value);
		Fixed&	operator=(const Fixed& object);

		bool	operator>(const Fixed& object) const;
		bool	operator<(const Fixed& object) const;
		bool	operator>=(const Fixed& object) const;
		bool	operator<=(const Fixed& object) const;
		bool	operator==(const Fixed& object) const;
		bool	operator!=(const Fixed& object) const;

		Fixed	operator+(const Fixed& object) const;
		Fixed	operator-(const Fixed& object) const;
		Fixed	operator*(const Fixed& object) const;
		Fixed	operator/(const Fixed& object) const;

		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

		static Fixed	&min(Fixed& a, Fixed& b);
		static Fixed	&max(Fixed& a, Fixed& b);
		static const Fixed	&min(const Fixed& a, const Fixed& b);
		static const Fixed	&max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& object);

#endif
