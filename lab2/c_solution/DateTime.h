#pragma once
#include <string.h>

#include "Date.h"
#include "Time.h"

struct DateTime
{
    struct Date _date;
    struct Time _time;

    char shortStrView[17];
};

void init_DateTime(struct DateTime*, const struct Date*, const struct Time*);
char* toShortString(struct DateTime*);