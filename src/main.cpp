#include "raylib.h"
#include "Parametros.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include "Juego.h"
#include <time.h>


int main(){
    InitWindow(ANCHO_PANTALLA, ALTO_PANTALLA, "Mi Pong");
    SetTargetFPS(FPS);
    Juego mi_juego;

    while(!WindowShouldClose()){
        mi_juego.Actualizar();
        PintarJuego(mi_juego);
    }
    
    CloseWindow();
    return 0;
}