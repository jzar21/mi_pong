#include "Parametros.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include "Juego.h"
#include <time.h>

Juego::Juego(){
    //iniciamos los objetos del juego con los datos correspondientes
    std::srand(time(0));
    float v_y = (float)(V_MIN + rand() % V_MAX * 2)/10;
    float v_x = (float)(V_MIN + rand() % V_MAX * 2)/10;
    
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
    if(Puntos_P1 < P_MAX && Puntos_P2 < P_MAX){//si nadie gana
        if(!marcar){// si no se ha marcado

            pelota.Mover(ancho, largo);
            pelota.RebotaBordes(ancho, largo);
            r_izd.MoverFlechas(Direccion2(), ancho, largo);
            r_dch.MoverFlechas(Direccion(), ancho, largo);

            // verificamos si la pelota choca en alguno de los ladrillos
            if(Colision(r_dch, pelota)){
                CambiaDireccion(r_dch, pelota);
            }
            if(Colision(r_izd, pelota)){
                CambiaDireccion(r_izd, pelota);
            }
            // si la pelota sobrepasa al ladrillo sumamos puntos y reiniciamos
            if(pelota.GetPosX() < posx_ini_izd ){
                Puntos_P2 ++;
                marcar = true;
            }

            if(pelota.GetPosX() > posx_ini_dch + ancho_barra){
                Puntos_P1++;
                marcar = true;
            }

            //aceleramos la pelota poco a poco
            pelota.SetDX(pelota.GetDX() * ACELELARION_PELOTA);

        }else{//si se marca se resetea el juego
            Reset();
        }
    }
}

void Juego::Reset(){//reiniciamos los valores de la pelota
    std::srand(time(0));
    float v_y = (float)(V_MIN + rand() % V_MAX * 2)/10;
    float v_x = (float)(V_MIN + rand() % V_MAX * 2)/10;

    pelota.SetDX(v_x);
    pelota.SetDY(v_y);
    pelota.SetPosX(ancho / 2);
    pelota.SetPosY(largo / 2); 

    marcar = false;
}

Circulo Juego::GetPelota() const{
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

void Juego::CambiaDireccion(const Rectangulo & r, Circulo & p){
    p.SetDX(p.GetDX() * -1.0f);//cambiamos la direccion de la pelota

    //normalizamos la posicion del impacto para que varie de -1 a 1
    float diferencia = (-r.GetPosY() - r.GetLargo() / 2 + p.GetPosY()) / (r.GetLargo() / 2 );
    //incrementamos la dy en proporcion a dx
    p.SetDY(diferencia * std::fabs(p.GetDX()));
}