#pragma once
#include <memory>
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
    static std::unique_ptr<Analyzer>  make_analyzer_by(Parser*);
    static std::unique_ptr<Analyzer>  make_analyzer_by(Analyzer*);

    virtual Token::Token getAnalysedToken() noexcept(false);
    inline void setNewParser(Parser*);
    void addKeyword(std::string&&);
    void addKeyword(const std::string&);

    Analyzer();
    Analyzer(Analyzer*);
    Analyzer(const Document*); // remove later
    virtual ~Analyzer() = default;
};
