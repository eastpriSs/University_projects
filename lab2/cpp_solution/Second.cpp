#include "Second.hpp"

Second::Second(int v) 
{
    if (v > 60 || v < 0)
    {    // exception
    }
    else value = v;
}


inline int Second::getValue() const
{
    return value;
} 