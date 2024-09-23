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


std::string Date::ToShortDateString()
{
    std::string str;
    // dd.mm.yyyy
    str.reserve(11);
    if (day.getNumber() < 10)
        str += '0';
    str += std::to_string(day.getNumber());
    
    str += '.';

    if (month.getNumber() < 10)
        str += '0';
    str += std::to_string(month.getNumber());
    
    str += '.';
    str += std::to_string(year.getNumber());

    return str;    
}