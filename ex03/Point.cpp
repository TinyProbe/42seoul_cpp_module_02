/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:09 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 19:06:29 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}
Point::Point(const float& x, const float& y) : x(x), y(y) {}
Point::Point(const Point& rhs) { *this = rhs; }
Point::~Point() {}
Point& Point::operator=(const Point& rhs) { return *this; }

const Fixed::Fixed& getX() const {
	return this->x;
}
const Fixed::Fixed& getY() const {
	return this->y;
}

Fixed Fixed::getLean(const Point& p1, const Point& p2) {
	Fixed dif_x = ABS__(a.x - b.x);
	Fixed dif_y = ABS__(a.y - b.y);

}
bool Fixed::getBinDir(const Point& b, const Point& e, const Point& cur) {

}
