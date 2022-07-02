#ifndef PINTAR_H
#define PINTAR_H
#include "raylib.h"
#include "Rectangulo.h"
#include "Pelota.h"

void PintarRectangulo(const Rectangulo &r, Color c);
void PintarPelota(const Pelota & p, Color c);

#endif