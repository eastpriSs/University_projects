#include "DateTime.h"

void init_DateTime(struct DateTime* this, const struct Date* d, const struct Time* t)
{
    this->shortStrView[0] = '\0';
    this->_date = *d;
    this->_time = *t;
}

char* toShortString(struct DateTime* this)
{
    if (this->shortStrView[0] != '\0') return NULL;
    strcat(this->shortStrView, toShortDateString(&this->_date));
    strcat(this->shortStrView, " ");
    strcat(this->shortStrView, toShortTimeString(&this->_time));
    return this->shortStrView;
}