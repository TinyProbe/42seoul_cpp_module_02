/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:50 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 16:09:22 by tkong            ###   ########.fr       */
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
bool Fixed::operator>(const Fixed& rhs) const {
	return this->toFloat() > rhs.toFloat();
}
bool Fixed::operator<(const Fixed& rhs) const {
	return this->toFloat() < rhs.toFloat();
}
bool Fixed::operator>=(const Fixed& rhs) const {
	return this->toFloat() >= rhs.toFloat();
}
bool Fixed::operator<=(const Fixed& rhs) const {
	return this->toFloat() <= rhs.toFloat();
}
bool Fixed::operator==(const Fixed& rhs) const {
	return this->toFloat() == rhs.toFloat();
}
bool Fixed::operator!=(const Fixed& rhs) const {
	return this->toFloat() != rhs.toFloat();
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
