#pragma once
#include <string>
#include <stdexcept>

class Day
{
private:
    int numberInMonth;
    inline bool isValidValue(const int& ); // static
public:
// in future add overload for rvalue
    void tryParse(const std::string&) noexcept(false);
    explicit Day(const int&);
    explicit Day(int&&);
    int getNumber() const;
};
