#pragma once
#include <stdio.h>
#include "Format.h"
#define DEFAULT_BUFFER_DOCUMENT_SIZE 1024

struct Document
{
    enum charColor formatChars[DEFAULT_BUFFER_DOCUMENT_SIZE];
    char chstr[DEFAULT_BUFFER_DOCUMENT_SIZE];
};

void outDocument(struct Document*);
void setFormat(struct Document*, int, int, enum charColor);
char* getBeginDocument(struct Document*); 
int init_Document(struct Document*, char*);
