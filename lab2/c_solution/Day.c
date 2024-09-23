#include "Day.h"


int init_Day(struct Day* this, int n)
{
    if (n < 0 || n > 31) return 1;
    this->_number = n;
    return 0;
}
int getNumberDay(struct Day* this)
{
    return this->_number;
}
