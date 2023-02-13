/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:50 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 04:14:44 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val() {
	std::cout << "Default constructor called\n";
}
Fixed::Fixed(const int& val) {
	std::cout << "Int constructor called\n";
	this->val = (val << this->float_bit);
}
Fixed::Fixed(const float& val) {
	std::cout << "Float constructor called\n";
	this->val = roundf(val * (1 << this->float_bit));
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
	return this->val;
}
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->val = raw;
}
int Fixed::toInt(void) const {
	return (this->val >> this->float_bit);
}
float Fixed::toFloat(void) const {
	return (float) this->val / (1 << this->float_bit);
}
