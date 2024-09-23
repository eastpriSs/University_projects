#include "Date.h"
#include <stdio.h>
int init_Date(struct Date* this, int d, int m, int y)
{
    int code = 0; 
    code += init_Day(&this->_day, d);
    code += init_Month(&this->_month, m);
    code += init_Year(&this->_year, y);
    return code;
}

char* toShortDateString(struct Date* this)
{
    // dd.mm.yyyy
    int dayVal = getNumberDay(&this->_day);
    if (dayVal < 10) {
        this->strview[0] = '0';
        this->strview[1] = '0' + dayVal;
    }
    else {
        this->strview[0] = '0' + (dayVal  / 10);
        this->strview[1] = '0' + (dayVal  % 10);
    }
    this->strview[2] = '.';

    
    int monthVal = getNumberMonth(&this->_month);
    if (monthVal < 10) {
        this->strview[3] = '0';
        this->strview[4] = '0' + monthVal;
    }
    else {
        this->strview[3] = '0' + (monthVal  / 10);
        this->strview[4] = '0' + (monthVal  % 10);
    }
    this->strview[5] = '.';

    int yearVal = getNumberYear(&this->_year);
    this->strview[6] = '0' + (yearVal  / 1000);
    this->strview[7] = '0' + ((yearVal  / 100) % 10);
    this->strview[8] = '0' + ((yearVal  % 100) / 10);
    this->strview[9] = '0' + (yearVal  % 10);

    this->strview[10] = '\0';
    return this->strview;
}