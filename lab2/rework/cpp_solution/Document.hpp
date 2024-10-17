#pragma once
#include <fstream>
#include <vector>
#include <iostream>

#include "Format.hpp"

namespace DocumentConst
{
	constexpr size_t DEFAULT_BUFFER_SIZE = 2048;
}

class Document
{
private:
    std::vector<Format::charColor> formatChars = std::vector<Format::charColor>(DocumentConst::DEFAULT_BUFFER_SIZE); 
    std::vector<char> chstr = std::vector<char>(DocumentConst::DEFAULT_BUFFER_SIZE);
public:
    void insertChar(std::vector<char>::const_iterator, char);
    void outDocument(std::ostream&);
    void setFormat(int, int, Format::charColor);
    inline std::vector<char>::const_iterator getBeginIterator() const { return chstr.begin(); } 
    Document(const std::string&);
    ~Document() = default;
};
