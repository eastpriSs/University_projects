#include "Day.hpp"


inline bool Day::isValidValue(const int& val)
{
    return val < 32 && val > 0;
}

Day::Day(const int& n)
{
    if (!isValidValue(n))
        throw 1;
    else 
        numberInMonth = n;
}

Day::Day(int&& n)
{
    if (!isValidValue(n))
        throw 1;
    else 
        numberInMonth = n;
}

int Day::getNumber() const
{ return numberInMonth; }