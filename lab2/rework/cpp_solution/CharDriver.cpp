#include "CharDriver.hpp"

void CharDriver::outCharStream(std::ostream& os)
{
    Format::ConsoleColor changeConsoleColor(os);
    for (int i = 0; chstr[i] != '\0'; ++i)
    {
        switch (formatChars[i])
        {
        case Format::charColor::deflt:
            break;
        case Format::charColor::red:
            changeConsoleColor(2, 0);
            break;
        }
        os << chstr[i];
        changeConsoleColor(7, 0);
    }
}


void CharDriver::setFormat(int begin, int end)
{
    for (int i = begin; i < end; ++i)
        formatChars[i] = Format::charColor::red;
}

void CharDriver::insertChar(std::vector<char>::const_iterator pos, char ch)
{
    chstr.insert(pos, ch);
}

CharDriver::CharDriver(const std::string& path)
{
    using std::ifstream;
    ifstream f(path);
    
    if (!f)
        throw std::invalid_argument("file did not open.");
    
    auto it = chstr.begin();
    while (f.get(*it)) ++it;
}