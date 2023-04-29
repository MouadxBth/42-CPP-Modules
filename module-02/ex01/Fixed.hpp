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
    ~Fixed();
	Fixed &operator=(const Fixed&);

    int getRawBits(void) const;
    void setRawBits(const int);

	Fixed(const int);
    Fixed(const float);

    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);
