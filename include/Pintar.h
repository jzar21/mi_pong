#ifndef PINTAR_H
#define PINTAR_H
#include "raylib.h"
#include "Rectangulo.h"
#include "Pelota.h"
#include "Juego.h"

void PintarRectangulo(const Rectangulo &r, Color c);
void PintarPelota(const Pelota & p, Color c);
void PintarJuego(const Juego &j);
#endif