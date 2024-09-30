#pragma once 
#include <string>
#include <stdexcept>

class Second
{
private:
    int value;
    inline bool isValidValue(const int& ); // static
public:
    void tryParse(const std::string&) noexcept(false);
    explicit Second(int);
    inline int getValue() const; 
};
