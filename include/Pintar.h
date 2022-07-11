#ifndef PINTAR_H
#define PINTAR_H
#include <raylib.h>
#include "Rectangulo.h"
#include "Circulo.h"
#include "Juego.h"

void PintarRectangulo(const Rectangulo &r, Color c);
void PintarPelota(const Circulo & p, Color c);
void PintarJuego(const Juego &j);
#endif