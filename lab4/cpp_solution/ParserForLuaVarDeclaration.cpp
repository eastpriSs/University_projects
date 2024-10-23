#include "ParserForLuaVarDeclaration.hpp"


/*

Упрощенная грамматика объявления переменной в языке lua

$t - терминал

S -> $local D | D
D -> ID | ID $= V
ID -> ...
V -> ...

*/

Token::Token ParserForLuaVarDeclaration::parse()
{
    
} 