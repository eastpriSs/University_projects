#include "Year.hpp"

void Year::tryParse(const std::string& str) noexcept(false)
{   
    number = std::stoi(str);
}

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

Year::Year(const std::string& str)
{
    tryParse(str);
}

int Year::getNumber() const
{
    return number;
}