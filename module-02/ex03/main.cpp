#include "Point.hpp"

int	main(void)
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);
	Point point(0, 0);

	if (bsp(a, b , c, point))
		std::cout << "Point " << point << " is inside the triangle "
			<< a << " "
			<< b << " "
			<< c
			<< std::endl;
	else
		std::cout << "Point " << point << " is outside the triangle "
			<< a << " "
			<< b << " "
			<< c
			<<  std::endl;

	return (0);
}
