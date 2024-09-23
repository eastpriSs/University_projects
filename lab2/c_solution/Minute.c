#include "Minute.h"

int init_Minute(struct Minute* this, int v)
{
    if (v > 59 || v < 0)
        return 1;
    this->_value = v;
    return 0;
}
int getValueMinute(struct Minute* this)
{
    return this->_value;
}