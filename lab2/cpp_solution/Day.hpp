#pragma once

class Day
{
private:
    int numberInMonth;
    inline bool isValidValue(const int& ); // static
public:
    explicit Day(const int&);
    explicit Day(int&&);
    int getNumber() const;
};
