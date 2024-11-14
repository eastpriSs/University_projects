#include "Analyzer.hpp"

Analyzer::Analyzer()
{
    lex = nullptr;
    pars = nullptr;
}


Analyzer::Analyzer(Analyzer* pc)
{
    lex = pc->lex;
    pars = pc->pars;
}

std::unique_ptr<Analyzer> Analyzer::make_analyzer_by(Analyzer* p)
{
    std::unique_ptr<Analyzer> a = std::make_unique<Analyzer>(p);
    return a;
}

std::unique_ptr<Analyzer> Analyzer::make_analyzer_by(Parser* p)
{
    std::unique_ptr<Analyzer> a = std::make_unique<Analyzer>();
    a->setNewParser(p);
    return a;
}

Analyzer::Analyzer(const Document* code)
{
    lex = new Lexer(code);
    pars = new Parser(lex);
}


Token::Token Analyzer::getAnalysedToken() noexcept(false)
{
    if (pars)
        return pars->parse();

    throw std::runtime_error("Analyzer::Parser* pars is nullptr.");
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