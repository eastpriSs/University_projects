#include <stdio.h>
#include <stdlib.h>
#include "DateTime.h"

int main()
{
    struct Time t;
    struct Time *pt = (struct Time*)malloc(sizeof(struct Time));
    init_Time(&t, 9, 18, 0);
    init_Time(pt, 1, 2, 3);
    
    struct Date d;
    struct Date *pd = (struct Date*)malloc(sizeof(struct Date));
    init_Date(&d, 23, 9, 2024);
    init_Date(pd, 1, 2, 1234);
    

    struct DateTime dt;
    struct DateTime *pdt = (struct DateTime*)malloc(sizeof(struct DateTime));
    init_DateTime(&dt, &d, &t);
    init_DateTime(pdt, pd, pt);

    print_DateTime(&dt);
    printf("\n");
    print_DateTime(pdt);
}