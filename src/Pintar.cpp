#include "Pintar.h"
#include "raylib.h"
#include "Rectangulo.h"
#include "Pelota.h"

void PintarRectangulo(const Rectangulo &r, Color c){
    DrawRectangle(r.GetPosX(), r.GetPosY(), r.GetAncho(), r.GetLargo(), c);
}

void PintarPelota(const Pelota &p, Color c){
    DrawCircle(p.GetPosX(), p.GetPosY(), p.GetRadio(), c);
}

void PintarJuego(const Juego &j){
    BeginDrawing();
    ClearBackground(BLACK);
    PintarRectangulo(j.GetP1(), WHITE);
    PintarRectangulo(j.GetP2(), WHITE);
    PintarPelota(j.GetPelota(), RED);
    EndDrawing();
}