#include "Point.hpp"

static Fixed ft_abs(const Fixed& value)
{
	Fixed result(value < 0 ? value * -1 : value);
	return (result);
}

static Fixed ft_area(const Point& first, const Point &second, const Point &third)
{
	Fixed result(ft_abs(
		first.getX() * (second.getY() - third.getY())
		+ second.getX() * (third.getY() - first.getY())
		+ third.getX() * (first.getY() - second.getY())));
	return (result);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return (false);
	Fixed vertexArea = ft_area(a, b, c);

	Fixed firstPart = ft_area(point, a, b);
	Fixed secondPart = ft_area(point, b, c);
	Fixed thirdPart = ft_area(point, c, a);

	if (firstPart == 0 || secondPart == 0 || thirdPart == 0)
		return (false);

	return ((firstPart + secondPart + thirdPart) == vertexArea);
}
