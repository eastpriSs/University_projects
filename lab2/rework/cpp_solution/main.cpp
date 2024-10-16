#include "Highlighter.hpp"
#include "CharDriver.hpp"

int main()
{
    CharDriver ch("test.txt");
    Highlighter h(&ch);
    CharDriver o = h.highlightCharStream();
    o.outCharStream(std::cout);
}