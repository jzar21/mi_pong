#include "Rectangulo.h"
#include <cmath>
#include "Pelota.h"

Rectangulo::Rectangulo(){
    largo = ancho = pos_x = pos_y = v_x = v_y = 0;
}

Rectangulo::Rectangulo(float largo, float ancho, float _pos_x, float _pos_y, float dx, float dy){
    pos_x = _pos_x;
    pos_y = _pos_y;
    v_x = dx;
    v_y = dy;
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
