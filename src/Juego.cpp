#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include "Juego.h"
#include <time.h>

Juego::Juego(){
    std::srand(time(0));
    float v_y = (float)(V_MIN + rand() % V_MAX)/10;
    float v_x = (float)(V_MIN + rand() % V_MAX)/10;

    pelota.SetDX(v_x);
    pelota.SetDY(v_y);
    pelota.SetRadio(t_pelota);
    pelota.SetPosX(ancho / 2);
    pelota.SetPosY(largo / 2); 

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

    Puntos_P1 = Puntos_P2 = 0;
    marcar = false;
}

void Juego::Actualizar(){
    if(Puntos_P1 < P_MAX && Puntos_P2 < P_MAX){
        if(!marcar){
            pelota.Mover(ancho, largo);
            pelota.RebotaBordes(ancho, largo);
            r_izd.MoverFlechas(Direccion2(), ancho, largo);
            r_dch.MoverFlechas(Direccion(), ancho, largo);

            if(Colision(r_dch, pelota) || Colision(r_izd, pelota))
                pelota.SetDX(pelota.GetDX() * -1.0f);

            if(pelota.GetPosX() < posx_ini_izd ){
                Puntos_P2 ++;
                marcar = true;
            }

            if(pelota.GetPosX() > posx_ini_dch + ancho_barra){
                Puntos_P1++;
                marcar = true;
            }

        }else{
            Reset();
        }
    }
}

void Juego::Reset(){
    std::srand(time(0));
    float v_y = (float)(V_MIN + rand() % V_MAX)/10;
    float v_x = (float)(V_MIN + rand() % V_MAX)/10;

    pelota.SetDX(v_x);
    pelota.SetDY(v_y);
    pelota.SetPosX(ancho / 2);
    pelota.SetPosY(largo / 2); 

    marcar = false;
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

int Juego::Puntos_p1() const{
    return Puntos_P1;
}

int Juego::Puntos_p2() const{
    return Puntos_P2;
}
