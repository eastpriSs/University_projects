#pragma once

class Month
{
private:
    int number;
    inline bool isValidValue(const int& ); // static
public:
    explicit Month(const int&);
    explicit Month(int&&);
    int getNumber() const;
};
