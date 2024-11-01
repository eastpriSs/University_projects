#include <fstream>
#include <vector>
#include <iostream>

#include "Format.hpp"

namespace DocumentConst
{
	constexpr size_t DEFAULT_BUFFER_SIZE = 2048;
}

template<typename CharT>
class Document
{
private:
    std::vector<Format::charColor> formatChars; 
    std::vector<CharT> chstr;
public:
    void setFormat(int, int, Format::charColor);
    inline typename std::vector<CharT>::const_iterator getBeginIterator() const { return chstr.begin(); } 
    Document(const std::string&);
    
    ~Document() = default;
    
    friend std::basic_ostream<CharT>& operator<<(std::basic_ostream<CharT>& os, const Document<CharT>& d)
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

    friend Document<CharT> operator+(const Document<CharT>& lhs, const Document<CharT>& rhs)
    {
        Document<CharT> res = lhs;
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

};

template<typename T>
void Document<T>::setFormat(int begin, int end, Format::charColor cl)
{
    for (int i = begin; i < end; ++i)
        formatChars[i] = cl;
}

template<typename CharT>
Document<CharT>::Document(const std::string& path)
{
    chstr.reserve(DocumentConst::DEFAULT_BUFFER_SIZE);
    formatChars.reserve(DocumentConst::DEFAULT_BUFFER_SIZE);

    std::basic_ifstream<CharT> f(path);
    
    if (!f)
        throw std::invalid_argument("file did not open.");
    
    CharT c;
    while (f.get(c)) 
    {
        chstr.push_back(c);
        formatChars.push_back(Format::charColor::White);
    }
}

typedef Document<char> document;
typedef Document<wchar_t> wdocument;
