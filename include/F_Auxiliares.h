#ifndef F_AUXILIARES_H
#define F_AUXILIARES_H

#include <cmath>
#include "Rectangulo.h"
#include "Circulo.h"
#include <raylib.h>

bool Colision(const Rectangulo & r, const Circulo &p);
char Direccion();
char Direccion2();

#endif