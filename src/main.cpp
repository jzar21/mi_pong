#include <raylib.h>
#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include "Juego.h"
#include <time.h>


int main(){
    InitWindow(ancho, largo, "Mi Pong");
    SetTargetFPS(60);
    Juego mi_juego;

    while(!WindowShouldClose()){
        mi_juego.Actualizar();
        PintarJuego(mi_juego);
    }
    
    CloseWindow();
    return 0;
}