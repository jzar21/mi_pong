#include <raylib.h>
#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"

char Direccion(){
    char dir = ' ';
    if (IsKeyDown(KEY_UP))
        dir = 'U';
    if (IsKeyDown(KEY_DOWN))
        dir = 'D';
    if (IsKeyDown(KEY_LEFT))
        dir = 'L';
    if (IsKeyDown(KEY_RIGHT))
        dir = 'R';
    return dir;
}

int main(){
    InitWindow(ancho, largo, "Mi Pong");

    Pelota pelota(10, 20, 20, 1, 1);
    Rectangulo r_izd(90, 20 , 90, 90, 1, 1);
    Rectangulo r();
            
    while(!WindowShouldClose()){
        pelota.Mover(ancho, largo);
        pelota.RebotaBordes(ancho, largo);
        r_izd.MoverFlechas(Direccion(), ancho, largo);
        


        //parte grafica
        BeginDrawing();
        ClearBackground(BLACK);
        PintarRectangulo(r_izd, WHITE);
        PintarPelota(pelota, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}