#include "Player.h"
#include <stdio.h>

void init_Player(struct Player* this, struct UiDefaultSettings* ui)
{
    this->money = 0;
    this->_sprite = ui->playerSprite;
}


void setSprite(struct Player* this, char s)
{
    this->_sprite = s;
}

void print_Player(struct Player* this)
{
    printf("%c", this->_sprite);
}
