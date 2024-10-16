#pragma once
#include <fstream>
#include <vector>
#include <iostream>

#include "Format.hpp"

namespace CharDriverConst
{
	constexpr size_t DEFAULT_BUFFER_SIZE = 2048;
}

class CharDriver
{
private:
    std::vector<Format::charColor> formatChars = std::vector<Format::charColor>(CharDriverConst::DEFAULT_BUFFER_SIZE); 
    std::vector<char> chstr = std::vector<char>(CharDriverConst::DEFAULT_BUFFER_SIZE);
public:
    void insertChar(std::vector<char>::const_iterator, char);
    void outCharStream(std::ostream&);
    void setFormat(int, int);
    inline std::vector<char>::const_iterator getBeginIterator() const { return chstr.begin(); } 
    CharDriver(const std::string&);
    ~CharDriver() = default;
};
