#pragma once
#include <Windows.h>
#include <iostream>

namespace Format
{
    enum class charColor
    {
        deflt, red
    };    
     

    class ConsoleColor
    {
    private:
        std::ostream* os;
        void SetColor(int, int);
    public:
        ConsoleColor(std::ostream&);
        std::ostream& operator()(int txt = 7, int bg = 0);  
    };

} // namespace Format