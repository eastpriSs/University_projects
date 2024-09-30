#include "Second.hpp"

void Second::tryParse(const std::string& str) noexcept(false)
{   
    value = std::stoi(str);
    if (!isValidValue(value)) throw std::invalid_argument("Invalid second " + str);
}

inline bool Second::isValidValue(const int& val)
{
    return val <= 59 && val >= 0; 
}

Second::Second(int v) 
{
    if (!isValidValue(v))
        throw 1;
    else 
        value = v;
}


inline int Second::getValue() const
{
    return value;
} 