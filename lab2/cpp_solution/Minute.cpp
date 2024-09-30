#include "Minute.hpp"

void Minute::tryParse(const std::string& str) noexcept(false)
{   
    value = std::stoi(str);
    if (!isValidValue(value)) throw std::invalid_argument("Invalid minute " + str);
}

inline bool Minute::isValidValue(const int& val)
{
    return val <= 59 && val >= 0;
}

Minute::Minute(int v) 
{
    if (!isValidValue(v))
        throw 1;
    else 
        value = v;
}


int Minute::getValue() const
{
    return value;
}