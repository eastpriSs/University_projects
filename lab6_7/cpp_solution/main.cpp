#include <ostream>
#include "TemplatedDocument/TemplatedDocument.hpp"

int main(int argc, char* argv[])
{
    document doc("lua.lua");
    wdocument docw("python.py");

    std::cout << "\n\n>>>Document<char>\n\n";
    std::cout << doc;

    std::cout << "\n\n>>>Document<wchar_t>\n\n";
    std::wcout << docw;

}


//  g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp AnalyzerForLuaDeclaration.cpp LexerForLuaVarDeclaration.cpp ParserForLuaVarDeclaration.cpp
