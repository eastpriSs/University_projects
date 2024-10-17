#pragma once
#include "Format.h"
#include "Document.h"
#include "Lexer.h"
#include "Token.h"

struct Highlighter
{
    struct Document*   chdr;
    struct Lexer*      lex;
};

struct Document* highlightCharStream(struct Highlighter*);
void addKeywords(struct Highlighter*, char* kws[], int amountkws);
void init_Highlighter(struct Highlighter*, struct Document*);
