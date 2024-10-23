#include "Analyzer.hpp"

Analyzer::Analyzer(const Document* code)
{
    lex = new Lexer(code);
    pars = new Parser(lex);
}


Token::Token Analyzer::getAnalysedToken()
{
    return pars->parse();
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