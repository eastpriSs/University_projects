#include "EventHandler.h"

enum EventType match()
{
    switch (toupper(_getch()))
    {
    case 'W': return PRESSED_W;
    case 'A': return PRESSED_A;
    case 'S': return PRESSED_S;
    case 'D': return PRESSED_D;
    case 'Q': return PRESSED_Q; 
    case 'E': return PRESSED_E; 
    }
    return PRESSED_UNKNOWN;
}