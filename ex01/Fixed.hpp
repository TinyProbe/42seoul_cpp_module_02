/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:49 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 04:14:44 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define ABS__(x) ((x) < 0 ? -(x) : (x))

class Fixed {
	static const int float_bit = 8;
	int val;

public:
	Fixed();
	Fixed(const int& val);
	Fixed(const float& val);
	Fixed(const Fixed& rhs);
	~Fixed();
	Fixed& operator=(const Fixed& rhs);
	std::ostream& operator<<(std::ostream& os) const;
	operator float() const;

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

};

#endif
