#include "Document.hpp"
#include "Highlighter.hpp"

int main(int argc, char* argv[])
{
    Document sources[2]= {Document("python.py"), Document("lua.lua")};
    Highlighter highlighters[2] = {Highlighter(&sources[0]),Highlighter(&sources[1])};   

    highlighters[0].addKeywords({"def", "if", "return", "else"});
    highlighters[1].addKeywords({"local"});

    for (int i = 0; i < 2; ++i) {
        std::cout << highlighters[i].highlightCharStream();
        std::cout << "\n\n";
    }
}


//  g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp AnalyzerForLuaDeclaration.cpp LexerForLuaVarDeclaration.cpp ParserForLuaVarDeclaration.cpp
