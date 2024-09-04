/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FixedPointNumber.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:42:24 by ysanchez          #+#    #+#             */
/*   Updated: 2024/08/13 18:49:26 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_value;
		static const int _fracbits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& copy);
		Fixed(const int i_value);
		Fixed(const float f_value);
		~Fixed(void);
		Fixed& operator=(const Fixed& src);

		bool operator>(const Fixed& src) const;
		bool operator>=(const Fixed& src) const;
		bool operator<(const Fixed& src) const;
		bool operator<=(const Fixed& src) const;
		bool operator==(const Fixed& src) const;
		bool operator!=(const Fixed& src) const;

		Fixed operator+(const Fixed& src) const;
		Fixed operator-(const Fixed& src) const;
		Fixed operator*(const Fixed& src) const;
		Fixed operator/(const Fixed& src) const;
		
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
	
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif