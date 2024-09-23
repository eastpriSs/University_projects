#pragma once
#include "UiSettings.h"
#include "PlayGroundSize.h"
#include "PlateMatrix.h"

struct PlayGround
{
    struct PlateMatrix ground;
};

void init_PlayGround(struct PlayGround*, int, int, struct UiDefaultSettings*);
void updateCoins(struct PlayGround*);
void clearPlayGround(struct PlayGround*);