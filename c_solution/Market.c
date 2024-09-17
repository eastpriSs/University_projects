#include "Market.h"
#include <stdio.h>

void init_Market(struct Market* this)
{
    this->_playerSkins[0].sprite = '&';
    this->_playerSkins[1].sprite = '#';
    this->_playerSkins[2].sprite = '~';
    this->_playerSkins[3].sprite = '+';
    this->_playerSkins[4].sprite = '@';
    this->_playerSkins[5].sprite = '\0';
    // costs
    this->_playerSkins[0].cost = '&';
    this->_playerSkins[1].cost = '#';
    this->_playerSkins[2].cost = '~';
    this->_playerSkins[3].cost = '+';
    this->_playerSkins[4].cost = '@';
    this->_amountSkins = 5;
}

void showSkins(struct Market* this)
{
    printf("\nChoose skin:\n");
    int i = 0;
    while (this->_playerSkins[i].sprite != '\0')
    {
        printf("%d. %c ", i, this->_playerSkins[i].sprite);
        ++i;
    }
    printf("\nCosts.\n");
    i = 0;
    while (this->_playerSkins[i].sprite != '\0')
    {
        printf("%d. %d ", i, this->_playerSkins[i].cost);
        ++i;
    }
}


int selectToBuySkin(struct Market* this)
{
    printf("\nEnter '%d' for exit:\n", this->_amountSkins);
    int number = 6;
    do
    {
        do {} while (scanf("%d", &number) != 1);
        if (number == this->_amountSkins) break;
        
    } while(number > 5 || number < 0);
    return number;
}

struct Skin openSkinMarket(struct Market* this)
{
    showSkins(this);
    int numberSkin = selectToBuySkin(this); 
    if (numberSkin == this->_amountSkins) return this->_playerSkins[this->_amountSkins - 1];
    else return this->_playerSkins[numberSkin];
}