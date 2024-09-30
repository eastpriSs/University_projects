#pragma once
#include <string>
#include <stdexcept>

class Hour
{
private:
    int value;
    inline bool isValidValue(const int& ); // static
public:
    void tryParse(const std::string&) noexcept(false);
    explicit Hour(int);
    int getValue() const;
};


