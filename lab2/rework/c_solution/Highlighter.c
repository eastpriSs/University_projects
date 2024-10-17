#include "Highlighter.h"

void init_Highlighter(struct Highlighter* this, struct Document* txt)
{
    this->chdr = txt;
    this->lex = (struct Lexer*)malloc(sizeof(struct Lexer));
    init_Lexer(this->lex, this->chdr);
}

void addKeywords(struct Highlighter* this, char* kws[], int amountkws)
{
    for (int i = 0; i < amountkws; ++i)
        addKeyword(this->lex, kws[i]);
}

struct Document* highlightCharStream(struct Highlighter* this)
{
    struct Token* currTkn = scan(this->lex);
    while (currTkn->stype != eof)
    {    
        switch (currTkn->stype)
        {
        case num:
            setFormat(this->chdr, currTkn->posStartOfWord, currTkn->posEndOfWord, green);
            break;
        
        case keyword:
            setFormat(this->chdr, currTkn->posStartOfWord, currTkn->posEndOfWord, blue);
            break;
        
        case id:
            setFormat(this->chdr, currTkn->posStartOfWord, currTkn->posEndOfWord, turquoise);
            break;
        
        default: setFormat(this->chdr, currTkn->posStartOfWord, currTkn->posEndOfWord, white);
        }
        free(currTkn);
        currTkn = scan(this->lex);
    }
    return this->chdr;
}