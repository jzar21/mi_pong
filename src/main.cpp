#include <raylib.h>
#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"

int main(){
    InitWindow(ancho, largo, "Mi Pong");

    Pelota pelota(10, 20, 20, 1, 1);
    Rectangulo r_izd(30, 10 , 10, 10, 1, 1);
    
    while(!WindowShouldClose()){
        pelota.Mover(ancho, largo);
        pelota.RebotaBordes(ancho, largo);

        BeginDrawing();
        ClearBackground(BLACK);
        PintarRectangulo(r_izd, WHITE);
        PintarPelota(pelota, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}