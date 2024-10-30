#include "Format.hpp"

Format::SetConsoleColor::SetConsoleColor(std::ostream& o)
{
    os = &o;
}

void Format::SetConsoleColor::SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

std::ostream& Format::SetConsoleColor::operator()(int txt, int bg) {
    SetColor(txt, bg);
    return *os;
}
