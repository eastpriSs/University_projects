#include "Second.h"

int init_Second(struct Second* this, int v)
{
    if (v > 59 || v < 0)
        return 1;
    this->_value = v;
    return 0;
}
int getValueSecond(struct Second* this)
{
    return this->_value;
}