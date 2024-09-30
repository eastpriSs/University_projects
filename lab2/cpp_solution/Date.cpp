#include "Date.hpp"

Date::Date(int d, int m, int y)
: year(y), month(m), day(d) 
{
}

Date::Date(const Day& d, const Month& m, const Year& y)
: year(y), month(m), day(d) 
{
}

Date::Date(Day&& d, Month&& m, Year&& y)
: year(y), month(m), day(d) 
{
}

std::string getNumberBeforeSymbols(std::string::const_iterator& begin,
                                    std::string::const_iterator& forward)
{
    while (std::isdigit(*forward))
        ++forward;
    return std::string(begin, forward);
}

void Date::tryParseShort(const std::string& str) noexcept(false)
{
    // dd\.mm\.yyyy
    // in future regex and skip whitespaces
    auto forward = str.begin();
    auto begin = str.begin();
    
    day.tryParse(getNumberBeforeSymbols(begin, forward));
    ++forward;
    begin = forward;

    month.tryParse(getNumberBeforeSymbols(begin, forward));
    ++forward;
    begin = forward;

    year.tryParse(getNumberBeforeSymbols(begin, forward));
    ++forward;
    begin = forward;
    
}

std::string Date::ToShortDateString(char sep)
{
    std::string str;
    // dd.mm.yyyy
    str.reserve(11);
    if (day.getNumber() < 10)
        str += '0';
    str += std::to_string(day.getNumber());
    
    str += sep;

    if (month.getNumber() < 10)
        str += '0';
    str += std::to_string(month.getNumber());
    
    str += sep;
    str += std::to_string(year.getNumber());

    return str;    
}