#include "Lexer.hpp"

Lexer::Lexer(CharDriver* cs)
{
    chst = cs;
    begin = chst->getBeginIterator();
    it = begin;
    forwardIt = it + 1;
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
        scanningToken.posStartOfWord = it - begin;
        scanningToken.posEndOfWord = forwardIt - begin;
    }
    else {
        scanningToken.stype = Token::shortTtype::unknown;
    }
    it = forwardIt;
    forwardIt = it + 1;
    return scanningToken;
}