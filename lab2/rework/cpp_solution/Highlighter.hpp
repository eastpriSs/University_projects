#pragma once
#include "Format.hpp"
#include "Document.hpp"
#include "Lexer.hpp"
#include "Token.hpp"

class Highlighter
{
private:
    // in future add RAII
    Document*   chdr = nullptr;
    Lexer*      lex = nullptr; 
public:
    [[nodiscard]]
    Document highlightCharStream();
    void addKeywords(std::vector<std::string>&&);
    Highlighter() = delete;
    Highlighter(Document*);
    Highlighter(Document*, Lexer*);
};
