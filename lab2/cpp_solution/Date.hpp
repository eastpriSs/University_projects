#include "Year.hpp"
#include "Month.hpp"
#include "Day.hpp"

#include <string>
#include <ctype.h>

class Date
{
private:
    Year year;
    Month month;
    Day day;
public:
    Date(int, int, int);
    Date(const Day&, const Month&, const Year&);
    Date(Day&&, Month&&, Year&&);

    void tryParseShort(const std::string&) noexcept(false);
    std::string ToShortDateString(char sep = '.');
};