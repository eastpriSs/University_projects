#include "Year.hpp"


inline bool Year::isValidValue(const int& val)
{
    return val > 0;
}

Year::Year(const int& n)
{
    if (!isValidValue(n))
        throw 1;
    else 
        number = n;
}

Year::Year(int&& n)
{
    if (!isValidValue(n))
        throw 1;
    else 
        number = n;
}


int Year::getNumber() const
{
    return number;
}