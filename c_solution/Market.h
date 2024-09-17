#pragma once
#include "Skin.h"

struct Market
{
    char _amountSkins;
    struct Skin _playerSkins[10];
};

void init_Market(struct Market*);
void showSkins(struct Market*);
int selectToBuySkin(struct Market*);
struct Skin openSkinMarket(struct Market*);