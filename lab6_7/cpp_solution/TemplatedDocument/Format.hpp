#pragma once
#include <Windows.h>
#include <iostream>

namespace Format
{
    enum class charColor
    {
        Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
        DarkGray, LightBlue, LightGreen, LightCyan, LightRed, 
        LightMagenta, Yellow, White
    };    
     

    template<typename CharT>
    class SetConsoleColor
    {
    private:
        std::basic_ostream<CharT>* os;
        void SetColor(int, int);
    public:
        SetConsoleColor(std::basic_ostream<CharT>&);
        std::basic_ostream<CharT>& operator()(int txt = 7, int bg = 0);  
    };

} // namespace Format


template<typename T>
Format::SetConsoleColor<T>::SetConsoleColor(std::basic_ostream<T>& o)
{
    os = &o;
}

template<typename T>
void Format::SetConsoleColor<T>::SetColor(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

template<typename T>
std::basic_ostream<T>& Format::SetConsoleColor<T>::operator()(int txt, int bg) {
    SetColor(txt, bg);
    return *os;
}