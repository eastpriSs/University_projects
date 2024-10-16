#pragma once
#include <iostream>

namespace Token
{
    enum class shortTtype
    {
        unknown, keyword, num, id, opeartor, eof
    };
    enum class ttype {
        unknown, 
        eof, lvar, plus, minus, comma, 
        div, mod, lfloat_num, lnum, lname
    };

    class Token
    {
    public:
        Token() : type(ttype::eof) {}
        Token(ttype t) : type(t) {}
        Token(shortTtype t) : stype(t) {}
        Token(shortTtype st, ttype t) : stype(st), type(t){}
        
        ttype type = ttype::eof;
        shortTtype stype = shortTtype::eof; 
        int posStartOfWord;
        int posEndOfWord;
    };
}