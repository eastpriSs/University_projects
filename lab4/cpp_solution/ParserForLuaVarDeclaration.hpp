#pragma once
#include "Parser.hpp"
#include "Token.hpp"

class ParserForLuaVarDeclaration final : public Parser 
{
private:

public:
    Token::Token parse() override;    
};

