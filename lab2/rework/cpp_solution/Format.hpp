#pragma once
#include <Windows.h>
#include <iostream>

namespace Format
{
    enum class charColor
    {
        black, red, green, yellow, blue, purple, turquoise, white
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