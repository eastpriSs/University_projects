#include "Scene.h"
#include <stdio.h>

void init_Scene(struct Scene* this, struct UiDefaultSettings* settings)
{
    this->_playground_n = settings->playgroundSize_n;
    this->_playground_m = settings->playgroundSize_m;
    this->_playerpos_n = 0;
    this->_playerpos_m = 0;
    init_PlayGround(&this->_pground, this->_playground_n, this->_playground_m, settings);
    init_Player(&this->_player, settings);
}


void refreshCoins(struct Scene* this)
{
    updateCoins(&this->_pground);
}

void refreshPlayground(struct Scene* this)
{
    clearPlayGround(&this->_pground);
}

void tryMovePlayerUp(struct Scene* this)
{
    if (this->_playerpos_n > 0) 
        this->_playerpos_n -= 1;
}
void tryMovePlayerLeft(struct Scene* this)
{
    if (this->_playerpos_m > 0)
        this->_playerpos_m -= 1;
}
void tryMovePlayerDown(struct Scene* this)
{
    if (this->_playerpos_n < this->_playground_n - 1) 
        this->_playerpos_n += 1;
}
void tryMovePlayerRight(struct Scene* this)
{
    if (this->_playerpos_m < this->_playground_m - 1) 
        this->_playerpos_m += 1;
}

void show(struct Scene* this)
{
    printf("Coins: %d\n", this->_player.money);
    for (int i = 0; i < this->_playground_n; ++i)
    {
        for (int j = 0; j < this->_playground_m; ++j)
        {
            char playerOnCurrentPlate = (i == this->_playerpos_n) && (j == this->_playerpos_m);
        
            if (playerOnCurrentPlate) {
                if (getPlateTypeOn(&this->_pground.ground, i, j) == COIN) {
                    this->_player.money += 1;
                    refreshPlayground(this);
                    refreshCoins(this);
                }
                print_Player(&this->_player);
            }
            else {
                print_Plate(getPlate(&this->_pground.ground, i, j));
            }
        }
        printf("\n");
    }
}