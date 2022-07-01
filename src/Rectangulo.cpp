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

bool Rectangulo::Colision(const Pelota &p)const{
    bool choque = false;
    bool g_izd, g_dch;
    
    //por simplicidad para este juego ignoramos los golpes arriba y abajo
    g_izd = p.GetPosX() + p.GetRadio() == pos_x && p.GetPosY() <= pos_y + largo && p.GetPosY() >= pos_y;
    g_dch = p.GetPosX() - p.GetRadio() == pos_x + ancho && p.GetPosY() <= pos_y + largo && p.GetPosY() >= pos_y;

    choque = g_izd || g_dch ;
    
    return choque;
}