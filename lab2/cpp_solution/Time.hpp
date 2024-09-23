#pragma once
#include <string>
#include "Hour.hpp"
#include "Minute.hpp"
#include "Second.hpp"

class Time
{
private:
    Hour hour;
    Minute minute;
    Second second;
public:
    Time(int, int, int);
    Time(const Hour&, const Minute&, const Second&);
    Time(Hour&&, Minute&&, Second&&);
    
    std::string ToShortTimeString();
};