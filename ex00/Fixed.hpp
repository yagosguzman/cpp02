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
		Fixed& operator = (const Fixed& src);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif