#pragma once
#include "Date.hpp"
#include "Time.hpp"

class DateTime
{
private:
    Time time;
    Date date;
public:
    DateTime() = default;
    DateTime(Date&&, Time&&);
    DateTime(const Date&, const Time&);

    std::string ToShortString();
};
