#pragma once
#include "Lexer.hpp"
#include <unordered_map>

class LexerForLuaVarDeclaration final : public Lexer
{
private:
    static std::unordered_map<std::string, Token::ttype> table;
public:
    LexerForLuaVarDeclaration(const Document*);
    Token::Token scan() override;
};