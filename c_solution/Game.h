#pragma once
#include <stdlib.h>

#include "Scene.h"
#include "EventHandler.h"


struct Game
{
    struct Scene scene;
    char isExec;
};

void init_Game(struct Game*, struct UiDefaultSettings *);
void exec(struct Game*);