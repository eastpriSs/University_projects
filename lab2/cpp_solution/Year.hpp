#pragma once

class Year
{
private:
    int number;
    inline bool isValidValue(const int& ); // static
public:
    explicit Year(const int&);
    explicit Year(int&&);
    int getNumber() const;
};
