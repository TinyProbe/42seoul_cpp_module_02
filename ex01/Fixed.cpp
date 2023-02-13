/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:50 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 16:08:13 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val() {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int& val) {
	std::cout << "Int constructor called\n";
	this->val = (ABS__(val) << float_bit);
	if (val < 0) {
		this->val = -(this->val);
	}
}
Fixed::Fixed(const float& val) {
	std::cout << "Float constructor called\n";
	this->val = ABS__(val) * (1 << float_bit);
	if (val < 0) {
		this->val = -(this->val);
	}
}
Fixed::Fixed(const Fixed& rhs) {
	std::cout << "Copy constructor called\n";
	*this = rhs;
}
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called\n";
	if (this == &rhs) {
		return *this;
	}
	val = rhs.val;
	return *this;
}
std::ostream& Fixed::operator<<(std::ostream& os) const {
	std::cout << "Left shift operator called\n";
	os << this->toFloat();
	return os;
}
Fixed::operator float() const {
	return this->toFloat();
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return val;
}
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	val = raw;
}
int Fixed::toInt(void) const {
	if (this->val < 0) {
		return -(-(this->val) >> float_bit);
	} else {
		return (this->val >> float_bit);
	}
}
float Fixed::toFloat(void) const {
	float rtn = ABS__(this->val);
	rtn /= (1 << float_bit);
	if (this->val < 0) {
		rtn = -rtn;
	}
	return rtn;
}
