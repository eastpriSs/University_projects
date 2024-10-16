#pragma once
#include <unordered_map>
#include "CharDriver.hpp"
#include "Token.hpp"

class Lexer
{
private:
    std::vector<char>::const_iterator begin;
    std::vector<char>::const_iterator it;
    std::vector<char>::const_iterator forwardIt;

public:
    Lexer() = delete;
    Lexer(CharDriver*);

    virtual Token::Token scan();

private: CharDriver* chst;
};