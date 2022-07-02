#ifndef F_AUXILIARES_H
#define F_AUXILIARES_H

#include <cmath>
#include "Rectangulo.h"
#include "Pelota.h"
#include "raylib.h"

const float DIFF = 0.001f;

bool Igual(float, float);
bool Colision(const Rectangulo & r, const Pelota &p);
char Direccion();
char Direccion2();

#endif