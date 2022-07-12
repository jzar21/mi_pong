#ifndef JUEGO_H
#define JUEGO_H

#include "Parametros.h"
#include "Circulo.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include <time.h>


class Juego{
private:
    Circulo pelota;
    Rectangulo r_izd;
    Rectangulo r_dch;
    int Puntos_P1;
    int Puntos_P2;
    bool marcar;

    //resetea la velocidad y direccion de la pelota
    void Reset();

    //cambia la direccion de la pelota y su velocidad dy
    void CambiaDireccion(const Rectangulo & r, Circulo & p);
public:
    Juego();

    //se llama en cada actualizacion del juego
    void Actualizar();

    Circulo GetPelota()const;
    Rectangulo GetP1()const;
    Rectangulo GetP2()const;

    //devuelve los puntos del jugador de la izquierda
    int Puntos_p1()const;

    //devuelve los puntos del jugador de la derecha
    int Puntos_p2()const;    
};

#endif