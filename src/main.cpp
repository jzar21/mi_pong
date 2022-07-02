#include "raylib.h"
#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"


int main(){
    InitWindow(ancho, largo, "Mi Pong");

    Pelota pelota(10, 200, t_pelota, v_pelota, v_pelota);

    Rectangulo r_izd(alto_barra, ancho_barra , posx_ini_izd, posy_ini, 0, v_barra);

    Rectangulo r_dch(alto_barra, ancho_barra, posx_ini_dch , posy_ini, 0, v_barra);
            
    while(!WindowShouldClose()){
        pelota.Mover(ancho, largo);
        pelota.RebotaBordes(ancho, largo);
        r_izd.MoverFlechas(Direccion2(), ancho, largo);
        r_dch.MoverFlechas(Direccion(), ancho, largo);

        if(Colision(r_dch, pelota) || Colision(r_izd, pelota))
            pelota.SetDX(pelota.GetDX() * -1.0f);


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