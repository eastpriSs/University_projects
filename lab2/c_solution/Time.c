#include "Time.h"

int init_Time(struct Time* this, int h, int m, int s)
{
    int code = 0; 
    code += init_Hour(&this->_hour, h);
    code += init_Minute(&this->_minute, m);
    code += init_Second(&this->_second, s);
    return code;
}

char* toShortTimeString(struct Time* this)
{
    // hh:mm
    int hourVal = getValueHour(&this->_hour);
    if (hourVal < 10) {
        this->strview[0] = '0';
        this->strview[1] = '0' + hourVal;
    }
    else {
        this->strview[0] = '0' + (hourVal  / 10);
        this->strview[1] = '0' + (hourVal  % 10);
    }
    this->strview[2] = ':';

    int minuteVal = getValueMinute(&this->_minute);
    if (minuteVal < 10) {
        this->strview[3] = '0';
        this->strview[4] = '0' + minuteVal;
    }
    else {
        this->strview[3] = '0' + (minuteVal  / 10);
        this->strview[4] = '0' + (minuteVal  % 10);
    }
    this->strview[5] = '\0';
    return this->strview;
}