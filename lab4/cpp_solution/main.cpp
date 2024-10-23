#include "Highlighter.hpp"
#include "Document.hpp"

// g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp

int main()
{
    Document a("lua.lua");
    Document b("add.txt");
    Document c = a + b;
    Highlighter h(&c);
    h.addKeywords({"function", "if", "then", "return", "else", "end", "local"});
    std::cout << h.highlightCharStream();
}
