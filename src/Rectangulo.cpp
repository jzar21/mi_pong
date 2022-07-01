#include "Rectangulo.h"
#include <cmath>
#include "Pelota.h"

using namespace std;

Rectangulo::Rectangulo(){
    largo = ancho = pos_x = pos_y = dx = dy = 0;
}

Rectangulo::Rectangulo(float largo, float ancho, float _pos_x, float _pos_y, float dx, float dy){
    pos_x = _pos_x;
    pos_y = _pos_y;
    this->dx = dx;
    this->dy = dy;
    SetAncho(ancho);
    SetLargo(largo);
}

void Rectangulo::SetLargo(float el_largo){
    largo = abs(el_largo);
}

void Rectangulo::SetAncho(float el_ancho){
    ancho = abs(el_ancho);
}

void Rectangulo::Mover(void){
    pos_x += dx ;
    pos_y += dy ;
}

void Rectangulo::Mover(float ancho, float alto){
    Mover();
    AjustarPosicion(ancho, alto);
}

void Rectangulo::AjustarPosicion(float ancho, float alto){
    if (p_x >= ancho - this->ancho)
        p_x = ancho - this ->ancho;

    else if (p_x <= ancho)
        p_x = ancho;

    if (p_y >= alto - this->largo)
        p_y = alto - this->largo;
    else if (p_y <= this->largo)
        p_y = this->largo;
}

float Rectangulo::GetLargo()const{
    return largo;
}

float Rectangulo::GetAncho()const{
    return ancho;
}

float Rectangulo::GetPosY()const{
    return pos_y;
}

float Rectangulo::GetPosX()const{
    return pos_x;
}