#include "Time.hpp"

Time::Time(int h, int m, int s)
: hour(h), minute(m), second(s) 
{
}

Time::Time(const Hour& h, const Minute& m, const Second& s)
: hour(h), minute(m), second(s) 
{
}

Time::Time(Hour&& h, Minute&& m, Second&& s)
: hour(h), minute(m), second(s) 
{
}

void Time::tryParseShort(const std::string& str) noexcept(false)
{
    // hh\.mm\.ss
    // in future regex and skip whitespaces
    auto forward = str.begin();
    auto begin = str.begin();
    
    hour.tryParse(getNumberBeforeSymbols(begin, forward));
    ++forward;
    begin = forward;

    minute.tryParse(getNumberBeforeSymbols(begin, forward));
    ++forward;
    begin = forward;

    second.tryParse(getNumberBeforeSymbols(begin, forward));
    ++forward;
    begin = forward;
    
}

std::string Time::ToShortTimeString()
{
    std::string str;
    // hh:mm
    str.reserve(6);
    
    int hourVal = hour.getValue(); 
    if (hourVal < 10)
        str = "0" + std::to_string(hourVal);
    else 
        str = std::to_string(hourVal);
    
    str += ':';
    
    int minuteVal = minute.getValue(); 
    if (minuteVal < 10)
        str += "0" + std::to_string(minuteVal);
    else 
        str += std::to_string(minuteVal);
    
    return str;
}