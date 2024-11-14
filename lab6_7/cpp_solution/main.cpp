#include <memory>
#include <vector>
#include "Document.hpp"
#include "AnalyzerForLuaDeclaration.hpp"
#include "Highlighter.hpp"

int main(int argc, char* argv[])
{
    std::vector<Document> docs;
    docs.reserve(10);
    docs.emplace_back("lua.lua");
    docs.emplace_back("lua1.lua");
    docs.emplace_back("python.py");
    docs.emplace_back("python1.py");
    docs.emplace_back("abc");
    docs.emplace_back("bca");
    docs.emplace_back("eac");

    auto res = std::find_if(docs.begin(), docs.end(), [&](const Document& a) -> bool 
                                                        { return a.getFilename() == "abc"; });
    if (res != docs.end())
        std::cout << "found";
    
    auto comp = [&](const Document& a, const Document& b) -> bool
                { return a.getFilename().compare(b.getFilename()) < 0; };

    std::sort(docs.begin(), docs.end(), comp);
    
    Document hidden("lua.lua");
    auto res2 = std::binary_search(docs.begin(), docs.end(), hidden, comp);

    if (res != docs.end())
        std::cout << "found";

}


//  g++ main.cpp Document.cpp Format.cpp Highlighter.cpp Lexer.cpp Parser.cpp Analyzer.cpp AnalyzerForLuaDeclaration.cpp LexerForLuaVarDeclaration.cpp ParserForLuaVarDeclaration.cpp
