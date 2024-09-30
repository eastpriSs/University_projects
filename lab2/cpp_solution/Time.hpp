#pragma once
#include <string>
#include "Hour.hpp"
#include "Minute.hpp"
#include "Second.hpp"
#include "ParsingDateTimeSupport.hpp"

class Time
{
private:
    Hour hour;
    Minute minute;
    Second second;
public:
    Time() = default;
    Time(int, int, int);
    Time(const Hour&, const Minute&, const Second&);
    Time(Hour&&, Minute&&, Second&&);
    
    void tryParseShort(const std::string&) noexcept(false);
    std::string ToShortTimeString();
};