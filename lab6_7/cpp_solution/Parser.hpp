#pragma once
#include "Lexer.hpp"
#include "Node.hpp"

class Parser
{

protected: 
    Lexer* lex;
    Token::Token currTkn = {};

public:
    Node* AST = nullptr;
    Parser(Lexer*);
    virtual ~Parser() = default;
    virtual Token::Token parse();
};

