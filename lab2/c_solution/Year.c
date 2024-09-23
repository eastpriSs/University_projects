#include "Year.h"


int init_Year(struct Year* this, int n)
{
    if (n < 0 && n > 9999) return 1;
    this->_number = n;
    return 0;
}
int getNumberYear(struct Year* this)
{
    return this->_number;
}
