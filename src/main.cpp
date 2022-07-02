#include "raylib.h"
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

char Direccion2(){
    char dir = ' ';
    
    if (IsKeyDown(KEY_W))
        dir = 'U';
    if(IsKeyDown(KEY_S))
        dir = 'D';
    if(IsKeyDown(KEY_A))
        dir = 'L';
    if(IsKeyDown(KEY_D))
        dir = 'R';
    return dir;
}

int main(){
    InitWindow(ancho, largo, "Mi Pong");

    Pelota pelota(10, 20, 20, .5, .5);
    Rectangulo r_izd(90, 20 , 20, largo/2 - 90, 0, .5);
    Rectangulo r_dch(90, 20, ancho - 40 , largo/2 - 90, 0, .5);
            
    while(!WindowShouldClose()){
        pelota.Mover(ancho, largo);
        pelota.RebotaBordes(ancho, largo);
        r_izd.MoverFlechas(Direccion2(), ancho, largo);
        r_dch.MoverFlechas(Direccion(), ancho, largo);

        if(r_izd.Colision(pelota) || r_dch.Colision(pelota))
            pelota.SetDX(pelota.GetDX() * -1);
        //parte grafica
        BeginDrawing();
        ClearBackground(BLACK);
        PintarRectangulo(r_izd, WHITE);
        PintarRectangulo(r_dch, WHITE);
        PintarPelota(pelota, RED);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}