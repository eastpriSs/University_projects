#include "Hour.hpp"

void Hour::tryParse(const std::string& str) noexcept(false)
{   
    value = std::stoi(str);
    if (!isValidValue(value)) throw std::invalid_argument("Invalid hour " + str);
}

inline bool Hour::isValidValue(const int& val)
{
    return val <= 23 && val >= 0; 
}

Hour::Hour(int v)
{
    if (!isValidValue(v))
        throw 1;
    else 
        value = v;
}


int Hour::getValue() const {return value;}