#include "Highlighter.hpp"
#include "AnalyzerForLuaDeclaration.hpp"
#include "Document.hpp"

// g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp

int main()
{
    Document a("lua.lua");
    Highlighter h(&a, new AnalyzerForLuaDeclaration(&a));
    h.addKeywords({"function", "if", "then", "return", "else", "end", "local"});
    std::cout << h.highlightCharStream();
}
