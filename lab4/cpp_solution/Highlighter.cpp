#include "Highlighter.hpp"

Highlighter::Highlighter(Document* chs)
{
    chdr = chs;
    anlzr = new Analyzer(chs);
}


Highlighter::Highlighter(Document* chs, Analyzer* a)
{
    chdr = chs;
    anlzr = a;
}

Highlighter& Highlighter::operator=(const Highlighter& rhs)
{
    chdr = new Document(*rhs.chdr);
    anlzr = new Analyzer(*rhs.anlzr);
    return *this;
}


void Highlighter::addKeywords(std::vector<std::string>&& kws)
{
    for (auto i = kws.begin(); i != kws.end(); ++i)
        anlzr->addKeyword(*i);
}

Document Highlighter::highlightCharStream()
{
    Token::Token currTkn = anlzr->getAnalysedToken();
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
        currTkn = anlzr->getAnalysedToken();
    }
    return *chdr;
}