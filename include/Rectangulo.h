#ifndef RECTANGULO_H
#define RECTANGULO_H
#include <cmath>
#include "Pelota.h"

class Rectangulo{
private:
    //pos_x y pos_y son la posicion de la esquina inferior izda
    float largo, ancho, pos_x, pos_y, dx, dy;
    void AjustarPosicion(float, float);
public:
    Rectangulo();
    Rectangulo(float, float, float, float, float, float);
    void SetLargo(float);
    void SetAncho(float);
    void Mover(void);
    void Mover(float, float);
    bool Colision(const Pelota & pelota)const;
    float GetLargo(void)const;
    float GetAncho(void)const;
    float GetPosX(void)const;
    float GetPosY(void)const;
    void MoverFlechas(char);
};


#endif