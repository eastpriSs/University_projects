#include "Lexer.h"

void init_Lexer(struct Lexer* this, struct Document* c)
{
    this->chst = c;
    this->kwamount = 0;
    this->keywords = (char**)malloc(sizeof(char*)*DEFAULT_KEYWORD_COUNT);
    for(int i = 0; i < DEFAULT_KEYWORD_COUNT; ++i)
        this->keywords[i] = (char *)malloc(sizeof(char)*21);
    this->begin = getBeginDocument(this->chst);
    this->it = this->begin;
    this->forwardIt = this->it + 1;     
} 
void addKeyword(struct Lexer* this, char* kw)
{
    this->keywords[this->kwamount++] = kw; 
}

char find(char *target, char *array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++) 
        if (strcmp(target, array[i]) == 0) 
            return 1;
    return 0;
}

struct Token* scan(struct Lexer* this)
{
    struct Token* scanningToken = (struct Token*)malloc(sizeof(struct Token));
    char lexem[20];
    if (*this->it == '\0') {
        scanningToken->stype = eof;
        return scanningToken;
    }
    else if (isdigit(*this->it)) {
        while (isdigit(*this->forwardIt)) ++this->forwardIt;
        scanningToken->stype = num;
    }
    else if (isalpha(*this->it)) {
        while (isalpha(*this->forwardIt) || isdigit(*this->forwardIt)) ++this->forwardIt;
        int i = 0;
        char *tmp = this->it;        
        while (tmp != this->forwardIt) { 
            lexem[i++] = *tmp;
            ++tmp;            
        }
        lexem[i] = '\0';
        if (find(lexem, this->keywords, this->kwamount))
            scanningToken->stype = keyword;
        else 
            scanningToken->stype = id;
    }
    else {
        scanningToken->stype = unknown;
    }
    scanningToken->posStartOfWord = this->it - this->begin;
    scanningToken->posEndOfWord = this->forwardIt - this->begin;
        
    this->it = this->forwardIt;
    this->forwardIt = this->it + 1;
    return scanningToken;
}