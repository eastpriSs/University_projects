#include <stdio.h>
#include "DateTime.h"

int main()
{
    struct Time t;
    init_Time(&t, 9, 18, 0);
    
    struct Date d;
    init_Date(&d, 23, 9, 2024);
    
    struct DateTime dt;
    init_DateTime(&dt, &d, &t);

    printf("%s", toShortString(&dt));
}