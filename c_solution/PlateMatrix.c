#include "PlateMatrix.h"
#include <stdlib.h>
#include <stdio.h>

int getN(struct PlateMatrix* this){ return this->_n; }
int getM(struct PlateMatrix*  this){ return this->_m; }

void init_PlateMatrix(struct PlateMatrix* this, int n, int m, struct UiDefaultSettings* sett)
{    
    this->_n = n;
    this->_m = m;
    this->_mtrx = (struct Plate**)(malloc(sizeof(struct Plate*) * n));
    for (int i = 0; i < n; ++i)
    {
        struct Plate* plateRow = (struct Plate*)(malloc(sizeof(struct Plate) * m));  
        
        for (int j = 0; j < m; ++j)
            init_Plate(plateRow + j, sett->plateSprite);
        
        this->_mtrx[i] = plateRow;
    }
}


void spawnCoinOn(struct PlateMatrix* this, int n, int m)
{
    this->_mtrx[n][m].type = COIN;
}

void clearPlate(struct PlateMatrix* this, int n, int m)
{
    this->_mtrx[n][m].type = DEFAULT;
}