#pragma once

enum shortTtype
{
    unknown, keyword, num, id, opeartor, eof
};

struct Token
{
    enum shortTtype stype; 
    int posStartOfWord;
    int posEndOfWord;
};

void init_Token(struct Token*, enum shortTtype st);

