#pragma once
#include "Parser.hpp"
#include "Token.hpp"

class ParserForLuaVarDeclaration final : public Parser 
{
private:
    void(ParserForLuaVarDeclaration::*ptrNextProduct)() = nullptr;

    void D();
    void X();
    void N();

public:
    ParserForLuaVarDeclaration() = default;
    ParserForLuaVarDeclaration(Lexer*);    
    Token::Token parse() override;    
};

