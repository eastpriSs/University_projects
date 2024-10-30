#include "AnalyzerForLuaDeclaration.hpp"

AnalyzerForLuaDeclaration::AnalyzerForLuaDeclaration(const Document* d)
: Analyzer()
{
    lex = new LexerForLuaVarDeclaration(d);
    pars = new ParserForLuaVarDeclaration(lex);
}


Token::Token AnalyzerForLuaDeclaration::getAnalysedToken()
{
    return pars->parse();
}