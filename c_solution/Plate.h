#pragma once

enum TypeOfPlate {DEFAULT, COIN};

struct Plate
{
    enum TypeOfPlate type;
    char _sprite;
    char _spriteWhenCoin;
};

void init_Plate(struct Plate*, char s);
void print_Plate(struct Plate*);