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
    pelota.SetRadio(TAM_PELOTA);
    pelota.SetPosX(ANCHO_PANTALLA / 2);
    pelota.SetPosY(ALTO_PANTALLA / 2); 

    r_izd.SetAncho(ANCHO_BARRA);
    r_izd.SetLargo(ALTO_BARRA);
    r_izd.SetPosX(PX_INICIAL_IZD);
    r_izd.SetPosY(PY_INICIAL);
    r_izd.SetDY(VELOCIDAD_BARRA);

    r_dch.SetAncho(ANCHO_BARRA);   
    r_dch.SetLargo(ALTO_BARRA);
    r_dch.SetPosX(PX_INICIAL_DCH);
    r_dch.SetPosY(PY_INICIAL);    
    r_dch.SetDY(VELOCIDAD_BARRA);

    Puntos_P1 = Puntos_P2 = 0;
    marcar = false;
}

void Juego::Actualizar(){
    if(Puntos_P1 < PUNTOS_GANADORES && Puntos_P2 < PUNTOS_GANADORES){//si nadie gana
        if(!marcar){// si no se ha marcado

            pelota.Mover(ANCHO_PANTALLA, ALTO_PANTALLA);
            pelota.RebotaBordes(ANCHO_PANTALLA, ALTO_PANTALLA);
            r_izd.MoverFlechas(Direccion2(), ANCHO_PANTALLA, ALTO_PANTALLA);
            r_dch.MoverFlechas(Direccion(), ANCHO_PANTALLA, ALTO_PANTALLA);

            // verificamos si la pelota choca en alguno de los ladrillos
            if(Colision(r_dch, pelota)){
                CambiaDireccion(r_dch, pelota);
            }
            if(Colision(r_izd, pelota)){
                CambiaDireccion(r_izd, pelota);
            }
            // si la pelota sobrepasa al ladrillo sumamos puntos y reiniciamos
            if(pelota.GetPosX() < PX_INICIAL_IZD ){
                Puntos_P2 ++;
                marcar = true;
            }

            if(pelota.GetPosX() > PX_INICIAL_DCH + ANCHO_BARRA){
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
    pelota.SetPosX(ANCHO_PANTALLA / 2);
    pelota.SetPosY(ALTO_PANTALLA / 2); 

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