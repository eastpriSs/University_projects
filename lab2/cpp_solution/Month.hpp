#pragma once
#include <string>
#include <stdexcept>

class Month
{
private:
    int number;
    inline bool isValidValue(const int& ); // static
public:
    void tryParse(const std::string&) noexcept(false);
    explicit Month(const int&);
    explicit Month(int&&);
    int getNumber() const;
};
