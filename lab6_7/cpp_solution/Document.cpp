#include "Document.hpp"

std::ostream& operator<<(std::ostream& os, const Document& d)
{
    Format::SetConsoleColor setConsoleColor(os);
    for (size_t i = 0; i < d.chstr.size(); ++i)
    {
        setConsoleColor(static_cast<int>(d.formatChars[i]), 0);
        os << d.chstr[i];
        setConsoleColor(static_cast<int>(Format::charColor::White), 0);
    }
    return os;
}

Document operator+(const Document& lhs, const Document& rhs)
{
    Document res = lhs;
    try 
    {
        res.formatChars.reserve(lhs.formatChars.capacity() + rhs.formatChars.capacity());
        res.chstr.reserve(lhs.chstr.capacity() + rhs.chstr.capacity());
    } 
    catch(std::length_error& len_e)
    {
        res.formatChars.reserve(lhs.formatChars.size() + rhs.formatChars.size());
        res.chstr.reserve(lhs.chstr.size() + rhs.chstr.size());
    }

    res.formatChars.insert(res.formatChars.end(), rhs.formatChars.begin(), rhs.formatChars.end());
    res.chstr.insert(res.chstr.end(), rhs.chstr.begin(), rhs.chstr.end());
    return res;
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
    chstr.reserve(DocumentConst::DEFAULT_BUFFER_SIZE);
    formatChars.reserve(DocumentConst::DEFAULT_BUFFER_SIZE);
    filename = path;

    using std::ifstream;
    ifstream f(path);
    
    if (!f)
        throw std::invalid_argument("file did not open.");
    
    char c;
    while (f.get(c)) 
    {
        chstr.push_back(c);
        formatChars.push_back(Format::charColor::White);
    }
}