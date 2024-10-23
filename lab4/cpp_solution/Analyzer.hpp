#pragma once
#include "Document.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"
#include "Token.hpp"

class Analyzer
{
private:
    Lexer* lex;
    Parser* pars;
    // + SemanticParser
public:
    Analyzer(const Document*);
    virtual Token::Token getAnalysedToken();
    inline void setNewParser(Parser*);
    inline void addKeyword(std::string&&);
    inline void addKeyword(const std::string&);
};
