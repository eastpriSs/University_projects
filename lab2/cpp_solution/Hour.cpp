#include "Hour.hpp"

Hour::Hour(int v){
    if (v > 24 || v < 0) {
        // exception
    }
    else value = v;
}


int Hour::getValue() const {return value;}