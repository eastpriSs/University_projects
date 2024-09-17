#pragma once
#include <conio.h>
#include <ctype.h>

enum EventType {PRESSED_W, PRESSED_A, PRESSED_S, 
                PRESSED_D, PRESSED_Q, PRESSED_E, PRESSED_UNKNOWN};

enum EventType match();