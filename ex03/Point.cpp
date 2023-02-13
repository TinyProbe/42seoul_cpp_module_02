/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:09 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 06:22:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}
Point::Point(const float& x, const float& y) : x(x), y(y) {}
Point::Point(const Point& rhs) { *this = rhs; }
Point::~Point() {}
Point& Point::operator=(const Point& rhs) { return *this; }
