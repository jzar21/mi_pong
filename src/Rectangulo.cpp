#include "Rectangulo.h"
#include <cmath>



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
    largo = std::abs(el_largo);
}

void Rectangulo::SetAncho(float el_ancho){
    ancho = std::abs(el_ancho);
}

void Rectangulo::SetPosY(float y){
    pos_y = y;
}

void Rectangulo::SetPosX(float x){
    pos_x = x;
}

void Rectangulo::SetDX(float dx){
    this->dx = dx;
}

void Rectangulo::SetDY(float dy){
    this->dy = dy;
}

void Rectangulo::Mover(void){
    pos_x += dx ;
    pos_y += dy ;
}

void Rectangulo::Mover(int ancho, int alto){
    Mover();
    AjustarPosicion(ancho, alto);
}

void Rectangulo::AjustarPosicion(int ancho, int alto){
    if (pos_x >= ancho - this->ancho)
        pos_x = ancho - this ->ancho;
    
    else if (pos_x <= 0)
        pos_x = 0;
    
    if (pos_y >= alto - this->largo)
        pos_y = alto - this->largo;

    else if (pos_y <= 0)
        pos_y = 0;
}

float Rectangulo::GetLargo(void)const{
    return largo;
}

float Rectangulo::GetAncho(void)const{
    return ancho;
}

float Rectangulo::GetPosY(void)const{
    return pos_y;
}

float Rectangulo::GetPosX(void)const{
    return pos_x;
}

float Rectangulo::GetDX(void)const{
    return dx;
}

float Rectangulo::GetDY(void)const{
    return dy;
}

void Rectangulo::MoverFlechas(char c, int ancho, int alto){
    
    if( c == 'U')
        pos_y -= dy;
    
    else if(c == 'D')
        pos_y += dy;
    
    else if(c == 'R')
        pos_x += dx;
    
    else if(c == 'L')
        pos_x -= dx;
    
    AjustarPosicion(ancho, alto);
}
