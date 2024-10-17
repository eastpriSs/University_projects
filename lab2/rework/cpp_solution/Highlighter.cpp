#include "Highlighter.hpp"

Highlighter::Highlighter(Document* chs)
{
    chdr = chs;
    lex = new Lexer(chs);
}


Highlighter::Highlighter(Document* chs, Lexer* l)
{
    chdr = chs;
    lex = l;
}


void Highlighter::addKeywords(std::vector<std::string>&& kws)
{
    for (auto i = kws.begin(); i != kws.end(); ++i)
        lex->addKeyword(*i);
}

Document Highlighter::highlightCharStream()
{
    Token::Token currTkn = lex->scan();
    while (currTkn.stype != Token::shortTtype::eof )
    {     
        switch (currTkn.stype)
        {
        case Token::shortTtype::num:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord, 
                            Format::charColor::green);
            break;
        
        case Token::shortTtype::keyword:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::blue);
            break;
        
        case Token::shortTtype::id:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::turquoise);
            break;
        
        default: chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::white);
        }
        currTkn = lex->scan();
    }
    return *chdr;
}