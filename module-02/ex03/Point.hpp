#pragma once

#include "Fixed.hpp"
#include <cmath>

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point&);
	Point operator=(const Point &);
	~Point();

	const Fixed &getX() const;
	const Fixed &getY() const;

	bool operator==(const Point &) const;
};

std::ostream &operator<<(std::ostream &, const Point &);

bool bsp( Point const a, Point const b, Point const c, Point const point);
