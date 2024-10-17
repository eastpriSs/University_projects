#include "Document.hpp"

void Document::outDocument(std::ostream& os)
{
    Format::SetConsoleColor setConsoleColor(os);
    for (int i = 0; chstr[i] != '\0'; ++i) // TODO: c-style code
    {
        setConsoleColor(static_cast<int>(formatChars[i]), 0);
        os << chstr[i];
        setConsoleColor(static_cast<int>(Format::charColor::white), 0);
    }
}


void Document::setFormat(int begin, int end, Format::charColor cl)
{
    for (int i = begin; i < end; ++i)
        formatChars[i] = cl;
}

void Document::insertChar(std::vector<char>::const_iterator pos, char ch)
{
    chstr.insert(pos, ch);
}

Document::Document(const std::string& path)
{
    using std::ifstream;
    ifstream f(path);
    
    if (!f)
        throw std::invalid_argument("file did not open.");
    
    auto it = chstr.begin();
    while (f.get(*it)) ++it;
}