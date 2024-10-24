#pragma once
#include "Document.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Token.hpp"

class Analyzer
{
protected:
    Lexer* lex;
    Parser* pars;
    // + SemanticParser
public:
    Analyzer(const Document*);
    virtual Token::Token getAnalysedToken();
    inline void setNewParser(Parser*);
    void addKeyword(std::string&&);
    void addKeyword(const std::string&);
};
