#include "Parser.hpp"

Parser::Parser(Lexer* l)
{
    lex = l;
}

Token::Token Parser::parse()
{
    return lex->scan();
}