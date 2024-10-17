#pragma once
#include "Document.h"
#include "Token.h"
#include <stdlib.h>
#define DEFAULT_KEYWORD_COUNT 25

struct Lexer
{
    char** keywords;
    char* begin;
    char* it;
    char* forwardIt;
    int kwamount; 
    struct Document* chst;
};

void init_Lexer(struct Lexer*, struct Document*);
void addKeyword(struct Lexer*, char*);
struct Token* scan(struct Lexer*);
