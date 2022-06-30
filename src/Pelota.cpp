#include "Pelota.h"
#include <cmath>

using namespace std;

Pelota::Pelota(){
    radio = p_x = p_y = dx = dy = 0;
}

Pelota::Pelota(float radio, float x, float y, float vx, float vy){
    p_x = x;
    p_y = y;
    dx = vx;
    dy = vy;
    SetRadio(radio);
}

void Pelota::SetRadio(float el_radio){
    radio = abs(el_radio);
}

void Pelota::Mover(void){
    p_x += dx;
    p_y += dy;
}

void Pelota::Mover(float ancho, float alto){
    Mover();
    AjustarPosiciones(ancho, alto);// evita que se salga de la pantalla
}

void Pelota::AjustarPosiciones(float ancho, float alto){
    if (p_x >= ancho - radio)
        p_x = ancho - radio;
    else if (p_x <= radio)
        p_x = radio;

    if (p_y >= alto - radio)
        p_y = alto - radio;
    else if (p_y <= radio)
        p_y = radio;
}

void Pelota::RebotaBordes(float ancho, float alto){
    if( p_x >= (ancho - radio) || (p_x - radio) <= 0)
        dx *= -1;
    if( p_y >= (alto - radio) || (p_y - radio) <= 0)
        dy *= -1;
}

float Pelota::GetPosX(void) const{
    return p_x;
}
float Pelota::GetPosY(void) const{
    return p_y;
}
float Pelota::GetRadio(void)const{
    return radio;
}