#include "Hour.h"
#include "Minute.h"
#include "Second.h"

struct Time
{
    struct Hour _hour;
    struct Minute _minute;
    struct Second _second;

    char strview[6];
};

int init_Time(struct Time*, int, int, int);
char* toShortTimeString(struct Time*);