#pragma once
#include "UiSettings.h"
#include "Plate.h"

struct PlateMatrix
{
    int _n, _m;
    struct Plate** _mtrx;
};

void init_PlateMatrix(struct PlateMatrix*, int, int, struct UiDefaultSettings*);
int getN(struct PlateMatrix*);
int getM(struct PlateMatrix*);
void spawnCoinOn(struct PlateMatrix*, int, int);
void clearPlate(struct PlateMatrix*, int, int);
enum TypeOfPlate getPlateTypeOn(struct PlateMatrix*, int, int);
const struct Plate* getPlate(struct PlateMatrix*, int, int);