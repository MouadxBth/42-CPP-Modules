#pragma once

#include <iostream>
#include <math.h>

class Fixed
{

private:
    int _value;
    static const int _fractionalPart = 8;

public:
    Fixed(void);
    Fixed(const Fixed&);
    Fixed(const int);
    Fixed(const float);
    Fixed &operator=(const Fixed&);

    ~Fixed(void);

    int getRawBits(void) const;
    void setRawBits(const int);

    float toFloat(void) const;
    int toInt(void) const;

	bool operator>(const Fixed &) const;
	bool operator<(const Fixed &) const;
	bool operator>=(const Fixed &) const;
	bool operator<=(const Fixed &) const;
	bool operator==(const Fixed &) const;
	bool operator!=(const Fixed &) const;

	Fixed operator+(const Fixed &) const;
	Fixed operator-(const Fixed &) const;
	Fixed operator*(const Fixed &) const;
	Fixed operator/(const Fixed &) const;

	Fixed operator++(void);
	Fixed operator--(void);

	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed &min(Fixed &, Fixed &);
	static const Fixed &min(const Fixed &, const Fixed &);

	static Fixed &max(Fixed &, Fixed &);
	static const Fixed &max(const Fixed &, const Fixed &);
};

std::ostream& operator<<(std::ostream&, const Fixed&);
