#pragma once
#include "Format.hpp"
#include "Document.hpp"
#include "Token.hpp"
#include "Analyzer.hpp"

class Highlighter
{
private:
    // in future add RAII
    Document*   chdr = nullptr;
    Analyzer*   anlzr = nullptr; 
public:
    [[nodiscard]]
    Document highlightCharStream() noexcept(false);
    void addKeywords(std::vector<std::string>&&);
    Highlighter() = delete;
    Highlighter(Document*);
    Highlighter(Document*, Analyzer*);
    Highlighter& operator=(const Highlighter&);
};
