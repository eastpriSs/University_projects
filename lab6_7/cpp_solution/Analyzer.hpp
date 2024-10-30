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
    Analyzer();
public:
    static Analyzer* make_analyzer_by(Parser*);

    virtual Token::Token getAnalysedToken() noexcept(false);
    inline void setNewParser(Parser*);
    void addKeyword(std::string&&);
    void addKeyword(const std::string&);

    Analyzer(const Document*); // remove later
    virtual ~Analyzer() = default;
};
