#include <iostream>
#include "DateTime.hpp"

int main()
{
    Time t(13, 48, 0);
    Date d(23, 9, 2024);

    DateTime dt(d, t);
    std::cout << dt.ToShortString();
}