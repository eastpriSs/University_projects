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

Document Highlighter::highlightCharStream() noexcept(false)
{
    Token::Token currTkn = anlzr->getAnalysedToken();
    while (currTkn.stype != Token::shortTtype::eof )
    {   
        switch (currTkn.stype)
        {
        case Token::shortTtype::num:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord, 
                            Format::charColor::Green);
            break;
        
        case Token::shortTtype::keyword:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::Blue);
            break;
        
        case Token::shortTtype::id:
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::Cyan);
            break;
        
        default: chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::White);
        }
        if (currTkn.syntaxError)
            chdr->setFormat(currTkn.posStartOfWord, currTkn.posEndOfWord,
                            Format::charColor::Yellow);
            
        currTkn = anlzr->getAnalysedToken();
    }
    return *chdr;
}