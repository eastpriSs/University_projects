#pragma once
#include "UiSettings.h"
#include "PlayGround.h"
#include "Player.h"

struct Scene
{
    struct PlayGround _pground;
    struct Player     _player;   
    int _playerpos_n, _playerpos_m;
    int _playground_n, _playground_m; 
};

void init_Scene(struct Scene*, struct UiDefaultSettings*);
void show(struct Scene*);

void tryMovePlayerUp(struct Scene*);
void tryMovePlayerLeft(struct Scene*);
void tryMovePlayerDown(struct Scene*);
void tryMovePlayerRight(struct Scene*);

void refreshCoins(struct Scene*);
void refreshPlayground(struct Scene*);
