#include "Document.h"

void outDocument(struct Document* this)
{
    for (int i = 0; this->chstr[i] != EOF; ++i)
    {
        SetConsoleColor(this->formatChars[i], 0);
        printf("%c", this->chstr[i]);
        SetConsoleColor(white, 0);
    }
    
}
void setFormat(struct Document* this, int s, int e, enum charColor cl)
{
    for (int i = s; i < e; ++i)
        this->formatChars[i] = cl;
}
char* getBeginDocument(struct Document* this)
{
    return this->chstr;
}

int init_Document(struct Document* this, char* file)
{
    FILE* fp = fopen(file, "r");
    
    if (fp == NULL) 
        return 1;

    int i = 0;
    while ((this->chstr[i] = fgetc(fp)) != EOF) {
        i++;
    }
    fclose(fp);
}