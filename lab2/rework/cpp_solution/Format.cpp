#include "Format.hpp"


Format::ConsoleColor::ConsoleColor(std::ostream& o)
{
    os = &o;
}

void Format::ConsoleColor::SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

std::ostream& Format::ConsoleColor::operator()(int txt, int bg) {
    SetColor(txt, bg);
    return *os;
}
