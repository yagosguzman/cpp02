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

#ifndef FIXEDPOINTNUMBER_HPP
# define FIXEDPOINTNUMBER_HPP

#include <iostream>

class FixedPointNum
{
	private:
		int	_value;
		static const int _fracbits;
	public:
		FixedPointNum(void);
		~FixedPointNum(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

};

#endif