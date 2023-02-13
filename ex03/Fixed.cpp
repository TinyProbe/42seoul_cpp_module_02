/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:50 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 22:59:45 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val() {}
Fixed::Fixed(const int& val) {
	this->val = (ABS__(val) << float_bit);
	if (val < 0) {
		this->val = -(this->val);
	}
}
Fixed::Fixed(const float& val) {
	this->val = ABS__(val) * (1 << float_bit);
	if (val < 0) {
		this->val = -(this->val);
	}
}
Fixed::Fixed(const Fixed& rhs) {
	*this = rhs;
}
Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this == &rhs) {
		return *this;
	}
	val = rhs.val;
	return *this;
}
std::ostream& Fixed::operator<<(std::ostream& os) const {
	os << this->toFloat();
	return os;
}
bool Fixed::operator>(const Fixed& rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}
bool Fixed::operator<(const Fixed& rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}
bool Fixed::operator>=(const Fixed& rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}
bool Fixed::operator<=(const Fixed& rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}
bool Fixed::operator==(const Fixed& rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}
bool Fixed::operator!=(const Fixed& rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}
Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}
Fixed& Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++*this;
	return tmp;
}
Fixed& Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--*this;
	return tmp;
}
Fixed::operator float() const {
	return this->toFloat();
}

int Fixed::getRawBits(void) const {
	return val;
}
void Fixed::setRawBits(int const raw) {
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

const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	if (lhs < rhs) {
		return lhs;
	}
	return rhs;
}
const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}
