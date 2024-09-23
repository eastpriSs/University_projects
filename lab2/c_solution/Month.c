#include "Month.h"


int init_Month(struct Month* this, int n)
{
    if (n < 0 || n > 12) return 1;
    this->_number = n;
    return 0;
}
int getNumberMonth(struct Month* this)
{
    return this->_number;
}
