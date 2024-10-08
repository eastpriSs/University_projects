#pragma once
#include <string>
#include <stdexcept>

class Minute
{
private:
    int value;
    inline bool isValidValue(const int& ); // static
public:
    void tryParse(const std::string&) noexcept(false);
    Minute() = default;
    explicit Minute(int);
    int getValue() const;
};
