#include "Circulo.h"
#include <cmath>

using namespace std;

Circulo::Circulo(){
    radio = p_x = p_y = dx = dy = 0;
}

Circulo::Circulo(float radio, float x, float y, float vx, float vy){
    p_x = x;
    p_y = y;
    dx = vx;
    dy = vy;
    SetRadio(radio);
}

void Circulo::SetRadio(float el_radio){
    radio = abs(el_radio);
}

void Circulo::Mover(void){
    p_x += dx;
    p_y += dy;
}

void Circulo::Mover(float ancho, float alto){
    Mover();
    AjustarPosiciones(ancho, alto);// evita que se salga de la pantalla
}

void Circulo::AjustarPosiciones(float ancho, float alto){
    if (p_x >= ancho - radio)
        p_x = ancho - radio;
    else if (p_x <= radio)
        p_x = radio;

    if (p_y >= alto - radio)
        p_y = alto - radio;
    else if (p_y <= radio)
        p_y = radio;
}

void Circulo::RebotaBordes(float ancho, float alto){
    if( p_x >= (ancho - radio) || (p_x - radio) <= 0)
        dx *= -1;
    if( p_y >= (alto - radio) || (p_y - radio) <= 0)
        dy *= -1;
}

float Circulo::GetPosX(void) const{
    return p_x;
}
float Circulo::GetPosY(void) const{
    return p_y;
}
float Circulo::GetRadio(void)const{
    return radio;
}

float Circulo::GetDX(void) const{
    return dx;
}

float Circulo::GetDY(void) const{
    return dy;
}

void Circulo::SetDX(float dx){
    this->dx = dx;
}

void Circulo::SetDY(float dy){
    this->dy = dy;
}
void Circulo::SetPosX(float x){
    p_x = x;
}
void Circulo::SetPosY(float y){
    p_y = y;
}
