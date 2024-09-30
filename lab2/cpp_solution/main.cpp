#include <iostream>
#include "DateTime.hpp"

int main()
{
    Time t(1, 1, 1);
    Date d(1, 1, 1);
    d.tryParseShort("23.9.2024");
    t.tryParseShort("9:41:30");
    DateTime dt(d, t);
    std::cout << dt.ToShortString();
}