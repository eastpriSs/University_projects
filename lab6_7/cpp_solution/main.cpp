#include "Document.hpp"
#include "AnalyzerForLuaDeclaration.hpp"
#include "Highlighter.hpp"
#include "Analyzer.hpp"

int main(int argc, char* argv[])
{
    Document d("lua.lua");
    Analyzer *base = new AnalyzerForLuaDeclaration(&d); 
    Highlighter h(&d, base);
    std::cout << h.highlightCharStream();
}


//  g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp AnalyzerForLuaDeclaration.cpp LexerForLuaVarDeclaration.cpp ParserForLuaVarDeclaration.cpp
