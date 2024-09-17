#include "Plate.h"
#include <stdio.h>

void init_Plate(struct Plate* this, char s)
{
    this->type = DEFAULT;
    this->_sprite = s;
    this->_spriteWhenCoin = '$';
}

void print_Plate(struct Plate* this)
{
    //Здесь можно делегировать обязанность в singlton
    if (this->type == COIN)
        printf("%c", this->_spriteWhenCoin);
    else if (this->type == DEFAULT)
        printf("%c", this->_sprite);
}