#include "Lexer.hpp"

Lexer::Lexer(Document* cs)
{
    chst = cs;
    begin = chst->getBeginIterator();
    keywords.reserve(DEFAULT_KEYWORD_COUNT);
    it = begin;
    forwardIt = it + 1;
}


void Lexer::addKeyword(std::string&& kw)
{
    keywords.push_back(kw);
}
void Lexer::addKeyword(const std::string& kw)
{
    keywords.push_back(kw);
}
    

Token::Token Lexer::scan()
{
    Token::Token scanningToken;
    if (*it == '\0') {
        return scanningToken;
    }
    else if (isdigit(*it)) {
        while (isdigit(*forwardIt)) ++forwardIt;
        scanningToken.stype = Token::shortTtype::num;
    }
    else if (isalpha(*it)) {
        while (isalpha(*forwardIt) || isdigit(*forwardIt)) ++forwardIt;
        std::string lexem = std::string(it, forwardIt);
        if (std::find(keywords.begin(), keywords.end(), lexem) != keywords.end())
            scanningToken.stype = Token::shortTtype::keyword;
        else 
            scanningToken.stype = Token::shortTtype::id;
    }
    else {
        scanningToken.stype = Token::shortTtype::unknown;
    }
    scanningToken.posStartOfWord = it - begin;
    scanningToken.posEndOfWord = forwardIt - begin;
        
    it = forwardIt;
    forwardIt = it + 1;
    return scanningToken;
}