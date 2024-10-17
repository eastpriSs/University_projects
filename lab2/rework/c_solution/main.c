#include "Highlighter.h"
#include "Document.h"

int main()
{
    char *kws[] = {"function", "if", "then", "return", "else", "end"};
    struct Document ch;
    init_Document(&ch, "test.txt");
    struct Highlighter h;
    init_Highlighter(&h, &ch);
    addKeywords(&h, kws, 6);
    struct Document* o = highlightCharStream(&h);
    outDocument(o);
}