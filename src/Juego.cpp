#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include <time.h>
#include "Juego.h"

Juego::Juego(){
    std::srand(time(NULL));
    float v_y = (float)(-2 + rand() % 1)/10;
    float v_x = (float)(-2 + rand() % 1)/10;

    pelota.SetDX(v_x);
    pelota.SetDY(v_y);
    pelota.SetRadio(t_pelota);
    pelota.SetPosX(largo / 2);
    pelota.SetPosY(ancho / 2);

    r_izd.SetAncho(ancho_barra);
    r_izd.SetLargo(alto_barra);
    r_izd.SetPosX(posx_ini_izd);
    r_izd.SetPosY(posy_ini);
    r_izd.SetDY(v_barra);

    r_dch.SetAncho(ancho_barra);   
    r_dch.SetLargo(alto_barra);
    r_dch.SetPosX(posx_ini_dch);
    r_dch.SetPosY(posy_ini);    
    r_dch.SetDY(v_barra);
}

void Juego::Actualizar(){
    pelota.Mover(ancho, largo);
    pelota.RebotaBordes(ancho, largo);
    r_izd.MoverFlechas(Direccion2(), ancho, largo);
    r_dch.MoverFlechas(Direccion(), ancho, largo);

    if(Colision(r_dch, pelota) || Colision(r_izd, pelota))
        pelota.SetDX(pelota.GetDX() * -1.0f);
}

Pelota Juego::GetPelota() const{
    return pelota;
}

Rectangulo Juego::GetP1()const{
    return r_izd;
}
Rectangulo Juego::GetP2()const{
    return r_dch;
}
