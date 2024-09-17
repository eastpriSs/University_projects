#include "UiSettings.h"
#include "Game.h"
#include <stdlib.h>

int main()
{
    struct UiDefaultSettings uiSetting;
    uiSetting.plateSprite = '.';
    uiSetting.playerSprite = '0';
    uiSetting.plateCoinSprite = '$';
    uiSetting.playgroundSize_n = 30;
    uiSetting.playgroundSize_m = 30;
    
    struct Game gm;
    init_Game(&gm, &uiSetting);
    exec(&gm);
}