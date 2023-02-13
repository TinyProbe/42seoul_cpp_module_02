/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:49 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 22:03:49 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {
	bool res1 = Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(1, 1));
	bool res2 = Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(10, 10));
	bool res3 = Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(10, 0));
	bool res4 = Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(8, 1));
	bool res5 = Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(11, 0));
	bool res6 = Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(3, 3));
	std::cout << "Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(1, 1)) : " << res1 << '\n';
	std::cout << "Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(10, 10)) : " << res2 << '\n';
	std::cout << "Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(10, 0)) : " << res3 << '\n';
	std::cout << "Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(8, 1)) : " << res4 << '\n';
	std::cout << "Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(11, 0)) : " << res5 << '\n';
	std::cout << "Point::bsp(Point(0, 0), Point(0, 10), Point(10, 0), Point(3, 3)) : " << res6 << '\n';
}
