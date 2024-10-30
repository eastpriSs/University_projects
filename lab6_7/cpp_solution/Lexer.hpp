#pragma once
#include "Document.hpp"
#include "Token.hpp"
#include <vector>
#include <algorithm>

class Lexer
{
private:
    static const int DEFAULT_KEYWORD_COUNT = 25;
    std::vector<std::string> keywords;
    std::vector<char>::const_iterator begin;
    std::vector<char>::const_iterator it;
    std::vector<char>::const_iterator forwardIt;

public:
    Lexer() = delete;
    Lexer(const Document*);
    Lexer(const Lexer&) = default;
    Lexer& operator=(const Lexer&) = default;
    virtual ~Lexer() = default;
    virtual void addKeyword(std::string&&);
    virtual void addKeyword(const std::string&);
    virtual Token::Token scan();

    
protected: const Document* chst;
};