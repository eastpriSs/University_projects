#include "Analyzer.hpp"


Analyzer::Analyzer()
{
    lex = nullptr;
    pars = nullptr;
}

// std::unique_ptr
// |
// V
Analyzer* Analyzer::make_analyzer_by(Parser* p)
{
    Analyzer *a = new Analyzer();
    a->setNewParser(p);
    return a;
}

Analyzer::Analyzer(const Document* code)
{
    lex = new Lexer(code);
    pars = new Parser(lex);
}


Token::Token Analyzer::getAnalysedToken()
{
    if (pars)
        return pars->parse();
    
    throw 1; // TODO
    return Token::Token();
}


void Analyzer::addKeyword(std::string&& kw)
{
    lex->addKeyword(kw);
}
void Analyzer::addKeyword(const std::string& kw)
{
    lex->addKeyword(kw);
}

void Analyzer::setNewParser(Parser* p)
{
    pars = p;
}