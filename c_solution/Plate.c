#include "Plate.h"
#include <stdio.h>

void init_Plate(struct Plate* this, struct UiDefaultSettings* uis)
{
    this->type = DEFAULT;
    this->_sprite = uis->plateSprite;
    this->_spriteWhenCoin = uis->plateCoinSprite;
}

void print_Plate(const struct Plate* this)
{
    //Здесь можно делегировать обязанность в singlton
    if (this->type == COIN)
        printf("%c", this->_spriteWhenCoin);
    else if (this->type == DEFAULT)
        printf("%c", this->_sprite);
}