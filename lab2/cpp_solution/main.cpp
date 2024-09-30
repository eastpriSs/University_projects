#include <iostream>
#include <random>
#include "DateTime.hpp"

int main()
{
    std::mt19937 gen(2);
    std::uniform_int_distribution<int> distSecond(1,59); 
    std::uniform_int_distribution<int> distMinute(1,59);
    std::uniform_int_distribution<int> distHour(1,23);

    std::uniform_int_distribution<int> distDay(1,31); 
    std::uniform_int_distribution<int> distMonth(1,12);
    std::uniform_int_distribution<int> distYear(0,9999);

    constexpr size_t size = 10;
    DateTime* dtArray[size]; 
    
    for (size_t i = 0; i < size; ++i)
    {
        dtArray[i] = new DateTime(
        Date(distDay(gen), distMonth(gen), distYear(gen)),
        Time(distHour(gen), distMinute(gen), distSecond(gen))
        );
    }
    
    for (size_t i = 0; i < size; ++i)
        std::cout << dtArray[i]->ToShortString() << '\n';

    for (size_t i = 0; i < size; ++i)
        delete dtArray[i];

}