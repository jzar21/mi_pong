#ifndef F_AUXILIARES_H
#define F_AUXILIARES_H

#include <cmath>
#include "Rectangulo.h"
#include "Circulo.h"
#include "raylib.h"

//verifica la colision de una pelota y un rectangulo
bool Colision(const Rectangulo & r, const Circulo &p);

//se usa para controlar un rectangulo con la flechas
char Direccion();

//se usa para controlar un rectangulo con "w", "a", "s", "d"
char Direccion2();

#endif