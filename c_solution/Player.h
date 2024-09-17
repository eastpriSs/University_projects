#pragma once
#include "UiSettings.h"

struct Player
{
    char _sprite;
    int money;
};

void init_Player(struct Player*, struct UiDefaultSettings*);
void print_Player(struct Player*);
void setSprite(struct Player*, char);