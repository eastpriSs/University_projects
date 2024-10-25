#include "Highlighter.hpp"
#include "Analyzer.hpp"
#include "Document.hpp"
#include "ParserForLuaVarDeclaration.hpp"
#include "LexerForLuaVarDeclaration.hpp"
//  g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp AnalyzerForLuaDeclaration.cpp LexerForLuaVarDeclaration.cpp ParserForLuaVarDeclaration.cpp

int main()
{
    Document a("lua.lua");
    LexerForLuaVarDeclaration* lex = new LexerForLuaVarDeclaration(&a);
    lex->addKeyword("local");
    Analyzer *an = Analyzer::make_analyzer_by(new ParserForLuaVarDeclaration(lex));
    Highlighter h(&a,an);
    std::cout << h.highlightCharStream();
}
