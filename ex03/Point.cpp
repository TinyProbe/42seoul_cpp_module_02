/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:09 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 23:16:15 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}
Point::Point(const float& x, const float& y) : x(x), y(y) {}
Point::Point(const Point& rhs) { *this = rhs; }
Point::~Point() {}
Point& Point::operator=(const Point& rhs) { (void) rhs; return *this; }

const Fixed& Point::getX() const {
	return this->x;
}
const Fixed& Point::getY() const {
	return this->y;
}

Fixed Point::getLean(const Point& p1, const Point& p2) {
	Fixed dif_x;
	Fixed dif_y;
	dif_x.setRawBits(p1.x.getRawBits() - p2.x.getRawBits());
	dif_y.setRawBits(p1.y.getRawBits() - p2.y.getRawBits());
	return dif_y / dif_x;
}
bool Point::getBinDir(const Point& b, const Point& e, const Point& cur) {
	return (Point::getLean(b, e) > Point::getLean(b, cur));
}
