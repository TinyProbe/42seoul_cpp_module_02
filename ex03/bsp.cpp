/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:10 by tkong             #+#    #+#             */
/*   Updated: 2023/02/13 18:58:44 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) {
	bool binDir1 = getBinDir(a, b, point);
	bool binDir2 = getBinDir(b, c, point);
	bool binDir3 = getBinDir(c, a, point);
	return (binDir1 == binDir2 && binDir2 == binDir3);
}
