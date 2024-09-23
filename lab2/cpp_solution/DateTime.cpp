#include "DateTime.hpp"


DateTime::DateTime(Date&& d, Time&& t)
: date (d), time (t)
{
}
DateTime::DateTime(const Date& d, const Time& t)
: date (d), time (t)
{
}


std::string DateTime::ToShortString()
{
    std::string str;
    // dd.mm.yyyy hh.mm
    str.reserve(17);
    str += date.ToShortDateString();
    str += " ";
    str += time.ToShortTimeString();
    return  str;
}