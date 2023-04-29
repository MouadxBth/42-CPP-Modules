#include "Fixed.hpp"

Fixed::Fixed(void)
	: _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value)
	: _value(value << _fractionalPart)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
	: _value(roundf(value * (1 << _fractionalPart)))
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
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &point)
{
	return (stream << point.toFloat());
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
float Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_fractionalPart));
}

int Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionalPart);
}

bool Fixed::operator>(const Fixed &point) const
{
	return (_value > point._value);
}

bool Fixed::operator<(const Fixed &point) const
{
	return (_value < point._value);
}

bool Fixed::operator>=(const Fixed &point) const
{
	return (_value >= point._value);
}

bool Fixed::operator<=(const Fixed &point) const
{
	return (_value <= point._value);
}

bool Fixed::operator==(const Fixed &point) const
{
	if (&point == this)
		return (true);
	return (_value == point._value);
}

bool Fixed::operator!=(const Fixed &point) const
{
	return (_value != point._value);
}

Fixed Fixed::operator+(const Fixed &point) const
{
	Fixed result;

	result.setRawBits(_value + point._value);
	return (result);
}

Fixed Fixed::operator-(const Fixed &point) const
{
	Fixed result;

	result.setRawBits(_value - point._value);
	return (result);
}

Fixed Fixed::operator*(const Fixed &point) const
{
	Fixed result;

	result.setRawBits(_value * point._value);
	return (result);
}

Fixed Fixed::operator/(const Fixed &point) const
{
	Fixed result;

	result.setRawBits(_value / point._value);
	return (result);
}

Fixed Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed result(*this);
	operator++();
	return (result);
}

Fixed Fixed::operator--(int)
{
	Fixed result(*this);
	operator--();
	return (result);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	return (first <= second ? first : second);
}
const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
	return (first <= second ? first : second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	return (first >= second ? first : second);
}
const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
	return (first >= second ? first : second);
}
