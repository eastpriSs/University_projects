#include "Hour.h"

int init_Hour(struct Hour* this, int v)
{
    if (v > 24 || v < 0)
        return 1;
    this->_value = v;
    return 0;
}
int getValueHour(struct Hour* this)
{
    return this->_value;
}