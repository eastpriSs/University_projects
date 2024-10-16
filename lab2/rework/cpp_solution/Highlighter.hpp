#pragma once
#include "CharDriver.hpp"
#include "Lexer.hpp"
#include "Token.hpp"

class Highlighter
{
private:
    CharDriver* chdr = nullptr;
    Lexer*      lex = nullptr;
public:
    [[nodiscard]]
    CharDriver highlightCharStream();
    Highlighter() = delete;
    Highlighter(CharDriver*);
};
