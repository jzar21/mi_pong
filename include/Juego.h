#ifndef JUEGO_H
#define JUEGO_H

#include "Parametros.h"
#include "Pelota.h"
#include "Rectangulo.h"
#include "Pintar.h"
#include "F_Auxiliares.h"
#include <random>
#include <time.h>


class Juego{
private:
    Pelota pelota;
    Rectangulo r_izd;
    Rectangulo r_dch;
public:
    Juego();
    void Actualizar();
    Pelota GetPelota()const;
    Rectangulo GetP1()const;
    Rectangulo GetP2()const;
};

#endif