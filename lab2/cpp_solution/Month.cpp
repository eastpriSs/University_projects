#include "Month.hpp"


inline bool Month::isValidValue(const int& val)
{
    return val < 13 && val > 0;
}

Month::Month(const int& n)
{
    if (!isValidValue(n))
        throw 1;
    else 
        number = n;
}

Month::Month(int&& n)
{
    if (!isValidValue(n))
        throw 1;
    else 
        number = n;
}


int Month::getNumber() const
{
    return number;
}