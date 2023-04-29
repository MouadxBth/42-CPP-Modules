#include "Point.hpp"

Point::Point()
{}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{}

Point::Point(const Point& point) : _x(point._x), _y(point._y)
{}
Point Point::operator=(const Point &src)
{
	Point result(src);
	return (result);
}

Point::~Point()
{}

const Fixed &Point::getX() const
{
	return (this->_x);
}

const Fixed &Point::getY() const
{
	return (this->_y);
}

bool Point::operator==(const Point &second) const
{
	return (getX() == second.getX() && getY() == second.getY());
}

std::ostream &operator<<(std::ostream &output, const Point &point)
{
	return (output << "( " << point.getX().toInt() << ", " << point.getY().toInt() << " )");
}
