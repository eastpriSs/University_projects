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
     

    class SetConsoleColor
    {
    private:
        std::ostream* os;
        void SetColor(int, int);
    public:
        SetConsoleColor(std::ostream&);
        std::ostream& operator()(int txt = 7, int bg = 0);  
    };

} // namespace Format