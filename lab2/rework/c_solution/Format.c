#include "Format.h"

void SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void SetConsoleColor(int txt, int bg) {
    SetColor(txt, bg);
}