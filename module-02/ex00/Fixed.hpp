#pragma once

#include <iostream>

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
};
