#include "Minute.hpp"

Minute::Minute(int v) 
{
    if (v > 60 || v < 0)
    {    // exception
    }
    else value = v;
}


int Minute::getValue() const
{
    return value;
}