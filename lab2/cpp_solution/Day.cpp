#include "Day.hpp"

void Day::tryParse(const std::string& str) noexcept(false)
{   
    numberInMonth = std::stoi(str);
    if (!isValidValue(numberInMonth)) throw std::invalid_argument("Invalid day " + str);
}

Day::Day()
{
    numberInMonth = 1;
}

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