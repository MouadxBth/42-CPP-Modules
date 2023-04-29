#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value) : _value(value << _fractionalPart)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalPart)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &right)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = right._value;
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &point)
{
	return (stream << point.toFloat());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
float Fixed::toFloat(void) const
{
	return ((float) this->_value / (float) (1 << this->_fractionalPart));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalPart);
}
