#include "ParsingDateTimeSupport.hpp"

std::string getNumberBeforeSymbols(std::string::const_iterator& begin,
                                    std::string::const_iterator& forward)
{
    while (std::isdigit(*forward))
        ++forward;
    return std::string(begin, forward);
}