#include "Highlighter.hpp"

Highlighter::Highlighter(CharDriver* chs)
{
    chdr = chs;
    lex = new Lexer(chs);
}


CharDriver Highlighter::highlightCharStream()
{
    Token::Token currTkn = lex->scan();
    while (currTkn.stype != Token::shortTtype::eof )
    {     
        switch (currTkn.stype)
        {
        case Token::shortTtype::num:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord);
            break;
        
        default:
            break;
        }
        currTkn = lex->scan();
    }
    return *chdr;
}