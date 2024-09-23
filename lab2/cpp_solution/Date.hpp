#include "Year.hpp"
#include "Month.hpp"
#include "Day.hpp"

#include <string>

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

    std::string ToShortDateString();
};