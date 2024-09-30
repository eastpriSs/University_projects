#pragma once
#include <string>
#include <stdexcept>

class Year
{
private:
    int number;
    inline bool isValidValue(const int& ); // static
public:
    void tryParse(const std::string&) noexcept(false);
    explicit Year(const int&);
    explicit Year(int&&);
    explicit Year(const std::string&);
    int getNumber() const;
};
