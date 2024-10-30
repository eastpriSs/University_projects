#include "ParserForLuaVarDeclaration.hpp"


/*

Упрощенная грамматика объявления переменной в языке lua

$t - терминал

S -> $local D
D -> ID e | X
X -> ID $= N e
ID -> ...
N -> ...

*/

ParserForLuaVarDeclaration::ParserForLuaVarDeclaration(Lexer* l)
: Parser(l)
{
}

void ParserForLuaVarDeclaration::N()
{
    currTkn = lex->scan();
    if (currTkn.type != Token::ttype::lnum)
        currTkn.syntaxError = true;
    ptrNextProduct = nullptr;
}

void ParserForLuaVarDeclaration::X()
{
    currTkn = lex->scan();
    if (currTkn.type == Token::ttype::lassgm)
        ptrNextProduct = &N;
    else 
        ptrNextProduct = nullptr;
}

void ParserForLuaVarDeclaration::D()
{
    currTkn = lex->scan();
    if (currTkn.type == Token::ttype::lname) { // ID
        ptrNextProduct = &X;
    }
    else { 
        currTkn.syntaxError = true;
        ptrNextProduct = nullptr;
    }
}

Token::Token ParserForLuaVarDeclaration::parse()
{
    if (ptrNextProduct != nullptr) {
        (this->*ptrNextProduct)();
    }
    else {
        currTkn = lex->scan();
        if (currTkn.type == Token::ttype::llocal)
            ptrNextProduct = &D;
    }
    return currTkn;
} 