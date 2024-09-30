#include <iostream>
#include "DateTime.hpp"

int main()
{
    Time t(13, 48, 0);
    Date d(1, 1, 1);
    d.tryParseShort("23.9.2024");
    DateTime dt(d, t);
    std::cout << dt.ToShortString();
}