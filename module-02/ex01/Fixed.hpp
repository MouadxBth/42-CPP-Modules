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
};

std::ostream& operator<<(std::ostream&, const Fixed&);
