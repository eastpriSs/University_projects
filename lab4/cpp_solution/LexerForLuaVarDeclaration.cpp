#include "LexerForLuaVarDeclaration.hpp"

std::unordered_map<std::string, Token::ttype> LexerForLuaVarDeclaration::table = {{"local", Token::ttype::llocal}};

LexerForLuaVarDeclaration::LexerForLuaVarDeclaration(const Document* d)
: Lexer(d)
{
}

Token::Token LexerForLuaVarDeclaration::scan()
{
    Token::Token t = Lexer::scan();
    std::string lexem = std::string(chst->getBeginIterator() + t.posStartOfWord,
                                    chst->getBeginIterator() + t.posEndOfWord );
    if (t.stype == Token::shortTtype::keyword) {
        if (LexerForLuaVarDeclaration::table.find(lexem) != LexerForLuaVarDeclaration::table.end())
            t.type = LexerForLuaVarDeclaration::table[lexem];
    }
    else if (lexem == "=") t.type = Token::ttype::lassgm;
    return t;
}