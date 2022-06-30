#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <cmath>
#include "Pelota.h"

class Rectangulo{
private:
    float largo, ancho, pos_x, pos_y, v_x, v_y;
public:
    Rectangulo();
    Rectangulo(float, float, float, float, float, float);
    void SetLargo(float);
    void SetAncho(float);
    void Mover(void);
    bool Colision(const Pelota & );
};


#endif