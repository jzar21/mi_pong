#include "Pintar.h"
#include <raylib.h>
#include "Rectangulo.h"
#include "Pelota.h"


void PintarRectangulo(const Rectangulo &r, Color c){
    DrawRectangle(r.GetPosX(), r.GetPosY(), r.GetAncho(), r.GetLargo(), c);
}

void PintarPelota(const Pelota &p, Color c){
    DrawCircle(p.GetPosX(), p.GetPosY(), p.GetRadio(), c);
}

void PintarJuego(const Juego &j){
    char texto [] = {j.Puntos_p1() + '0', ' ', '-', ' ', '0' + j.Puntos_p2()};
    
    BeginDrawing();
    ClearBackground(BLACK);
    PintarRectangulo(j.GetP1(), WHITE);
    PintarRectangulo(j.GetP2(), WHITE);
    PintarPelota(j.GetPelota(), RED);

    //ajustado para que quede en el centro
    DrawText(texto, P_X_TXT - TAM_LETRA, P_Y_TXT, TAM_LETRA, WHITE);

    if(j.Puntos_p1() == P_MAX)
        DrawText("P1 HA GANADO", P_X_TXT - 4.5 * TAM_LETRA , largo / 2 - TAM_LETRA, TAM_LETRA, WHITE);

    if(j.Puntos_p2() == P_MAX)
        DrawText("P2 HA GANADO", P_X_TXT - 4.5 * TAM_LETRA, largo / 2 - TAM_LETRA, TAM_LETRA, WHITE);
    DrawFPS(10, 10);  
    EndDrawing();
}
