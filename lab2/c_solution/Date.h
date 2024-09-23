#include "Year.h"
#include "Month.h"
#include "Day.h"

struct Date
{
    struct Year _year;
    struct Month _month;
    struct Day _day;

    char strview[11];
};

int init_Date(struct Date*, int, int, int);
char* toShortDateString(struct Date*);