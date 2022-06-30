#include <raylib.h>
#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"

int main(){
    InitWindow(ancho_pantalla, largo_pantalla, "hollaaaa");
    Pelota pelota(10, 20, 20 ,1 , 1);
    Rectangulo r_izd(30, 10 , 10, 10, 1, 1);
    
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(BLACK);
        DrawRectangle(r_izd.GetPosX(), r_izd.GetPosY(), r_izd.GetAncho(), r_izd.GetLargo(), WHITE);
        DrawCircle(pelota.GetPosX(), pelota.GetPosY(), pelota.GetRadio(), RED);
        pelota.Mover(ancho_pantalla, largo_pantalla);
        pelota.RebotaBordes(ancho_pantalla, largo_pantalla);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}