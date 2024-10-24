#pragma once 
#include "Document.hpp"
#include "Analyzer.hpp"
#include "ParserForLuaVarDeclaration.hpp"
#include "LexerForLuaVarDeclaration.hpp"

class AnalyzerForLuaDeclaration final : public Analyzer
{
public:
    virtual Token::Token getAnalysedToken() override;
    AnalyzerForLuaDeclaration(const Document*);
};

