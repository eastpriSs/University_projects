#include "Highlighter.hpp"
#include "Document.hpp"

int main()
{
    Document ch("test.txt");
    Highlighter h(&ch);
    h.addKeywords({"function", "if", "then", "return", "else", "end"});
    Document o = h.highlightCharStream();
    o.outDocument(std::cout);
}