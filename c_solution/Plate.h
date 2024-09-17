#pragma once
#include "UiSettings.h"

enum TypeOfPlate {DEFAULT, COIN};

struct Plate
{
    enum TypeOfPlate type;
    char _sprite;
    char _spriteWhenCoin;
};

void init_Plate(struct Plate*, struct UiDefaultSettings*);
void print_Plate(const struct Plate*);