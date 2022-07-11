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
    void Reset();
    void CambiaDireccion(const Rectangulo & r, Circulo & p);
public:
    Juego();
    void Actualizar();
    Circulo GetPelota()const;
    Rectangulo GetP1()const;
    Rectangulo GetP2()const;
    int Puntos_p1()const;
    int Puntos_p2()const;    
};

#endif