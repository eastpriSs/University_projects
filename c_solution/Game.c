#include "Game.h"

#ifdef _WIN32
void clearConsole()
{ system("cls"); }
#endif
#ifdef linux
void clearConsole()
{ system("clear") }
#endif

void init_Game(struct Game* this, struct UiDefaultSettings *uiset)
{
    init_Scene(&this->scene, uiset);
}

void exec(struct Game* this)
{
    this->isExec = 1;
    while (this->isExec)
    {
        clearConsole();  
        show(&this->scene);
        switch (match())
        {
        case PRESSED_W:
            tryMovePlayerUp(&this->scene);
            break;
        case PRESSED_A:
            tryMovePlayerLeft(&this->scene);
            break;
        case PRESSED_S:
            tryMovePlayerDown(&this->scene);
            break;
        case PRESSED_D:
            tryMovePlayerRight(&this->scene);
            break;
        case PRESSED_E:
            refreshPlayground(&this->scene);
            refreshCoins(&this->scene);
            break;
        case PRESSED_Q:
            this->isExec = 0;
            break;
        
        default:
            break;
        }
    }
}