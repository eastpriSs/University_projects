#include "PlayGround.h"
#include <stdlib.h>
#include <time.h>

void init_PlayGround(struct PlayGround* this, int n, int m, struct UiDefaultSettings* sett)
{
    init_PlateMatrix(&this->ground, n, n, sett);
}

void updateCoins(struct PlayGround* this)
{
    srand(time(0));
    for (int i = 0; i < getN(&this->ground); ++i)
    {
        for (int j = 0; j < getM(&this->ground); ++j)
        {
            int s = 1;
            int e = 10;
            if ((rand() % (e - s + 1) + s) == 2)
            {
                spawnCoinOn(&this->ground, i, j);
            }
        }
    }
}


void clearPlayGround(struct PlayGround* this)
{
    for (int i = 0; i < getN(&this->ground); ++i)
    {
        for (int j = 0; j < getM(&this->ground); ++j)
        {
            clearPlate(&this->ground, i, j);
        }
    }
}