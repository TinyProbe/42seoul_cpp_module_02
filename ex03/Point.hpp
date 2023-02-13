/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:08 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 06:38:24 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	const Fixed x;
	const Fixed y;

public:
	Point();
	Point(const float& x, const float& y);
	Point(const Point& rhs);
	~Point();
	Point& operator=(const Point& rhs);

	static bool bsp(Point const a, Point const b, Point const c, Point const point);

};

#endif
